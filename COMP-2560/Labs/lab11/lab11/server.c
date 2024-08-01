#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

void handle(int conn_fd);

int main(int argc, char *argv[])
{
	int domain = AF_INET;//Network Protocol: TCP/IP
	int type = SOCK_STREAM;//Connection-Oriented
	int protocol = 0;//Default transport: TCP for Internet connection-oriented

	int server_sd;
	server_sd = socket(domain, type, protocol);
	if (server_sd == -1)
	{
		printf("error in creating socket for The Server!\n");
		exit(1);
	}
	else
		printf("socket has created for The Server  with sd:%d\n", server_sd);

	//Binding
	struct in_addr server_sin_address;
	server_sin_address.s_addr = inet_addr(argv[1]);
	int server_sin_port = htons(atoi(argv[2]));

	struct sockaddr_in server_sin;
	server_sin.sin_family = domain;
	server_sin.sin_addr = server_sin_address;
	server_sin.sin_port = server_sin_port;
	int result = bind(server_sd, (struct sockaddr *) &server_sin, sizeof(server_sin));
	if (result == -1)
	{
		printf("error in binding The Server to the address:port = %d:%d\n", server_sin.sin_addr, server_sin.sin_port);
		exit(1);
	}
	else
		printf("The Server bound to the address:port = %d:%d\n", server_sin.sin_addr, server_sin.sin_port);

	//The Server ready to receive calls (up to 5 calls. More are rejected!)
	if (listen(server_sd, 5) < 0)
	{
		perror("The Server's listening failed!\n");
		exit(1);
	}

	struct sockaddr_in client_sin;//Contains sender's address
	int client_sin_len;
	while(1)
	{
		result = accept(server_sd, (struct sockaddr *) &client_sin, &client_sin_len);
		if (result == -1)
		{
			printf("error in opening the request from client %d:%d !\n", client_sin.sin_addr, client_sin.sin_port);
		}
		else //fork here?
		{
			pid_t pid = fork();
			if(pid == 0)//child
			{
				printf("The Server opened the request from client %d:%d\n", client_sin.sin_addr, client_sin.sin_port);
				handle(result);
				exit(0);
			}
		}
	}

}
//handles the given conn_fd
void handle(int conn_fd)
{
	while(1)
	{
		int nums[2];

		recv(conn_fd, nums, 2 * sizeof(int), 0);
		//printf("Received: %d and %d\n", nums[0], nums[1]); //num rec
		//char ret[] = "I am responding to you."; //misc resp prob remove
		//send(conn_fd, ret, strlen(ret), 0);

		//acc details
		char acc[128] = "";
		recv(conn_fd, acc, 128, 0);

		char username[50] = "";
		char password[50] = "";
		char *acc_details = strtok(acc, "|"); //user
		strcpy(username, acc_details);
		acc_details = strtok(NULL, "|");
		strcpy(password, acc_details);

		//printf("Username recvd: %s\n", username);
		//printf("Password recvd: %s\n", password);
		//Validate
		char auth_error[] = "Authentication failed!";
		if (strcmp(username, "comp2560") != 0)
		{
			send(conn_fd, auth_error, strlen(auth_error), 0);
		} else if (strcmp(password, "f2022") != 0)
		{
			send(conn_fd, auth_error, strlen(auth_error), 0);
		} else
		{
			char valid_auth_msg[] = "Authenticated successfully";
			send(conn_fd, valid_auth_msg, strlen(valid_auth_msg), 0);
			//Calc stuff

			pid_t pid = fork();
			if (pid == 0)
			{
				int result = nums[0] + nums[1];
				send(conn_fd, &result, sizeof(int), 0);
				exit(0);
			}
		}
	}
}


