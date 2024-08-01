#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int domain = AF_INET;//Network Protocol: TCP/IP
	int type = SOCK_STREAM;//Connection-Oriented
	int protocol = 0;//Default transport: TCP for Internet connection-oriented

	int client_sd;//socket descriptor ~= file descriptor
	client_sd = socket(domain, type, protocol);
	if (client_sd == -1)
	{
		printf("error in creating socket for the client!\n");
		exit(1);
	}
	else
		printf("socket has created for the client with sd:%d\n", client_sd);

	struct in_addr server_sin_address;
	server_sin_address.s_addr = inet_addr(argv[1]);
	int server_sin_port = htons(atoi(argv[2]));

	struct sockaddr_in server_sin;
	server_sin.sin_family = domain;
	server_sin.sin_addr = server_sin_address;
	server_sin.sin_port = server_sin_port;

	int result = connect(client_sd, (struct sockaddr *) &server_sin, sizeof(server_sin));
	if (result == -1)
	{
		printf("error in connecting to The Server at address:port = %d:%d\n", server_sin.sin_addr,
			   server_sin.sin_port);
		exit(1);
	}

	while(1)
	{
		int nums[2];
		printf("Enter a number: ");
		scanf("%d", &nums[0]);
		printf("Enter a second number: ");
		scanf("%d", &nums[1]);
		send(client_sd, nums, 2 * sizeof(int), 0);
		//acc details
		char username[100] = "";
		char password[100] = "";
		printf("Enter username: ");
		scanf("%s", username);
		printf("Enter password: ");
		scanf("%s", password);
		strcat(username, "|");
		strcat(username, password);

		send(client_sd, username, strlen(username), 0);
		//printf("Acc details sent\n");
		//Wait for auth
		char buffer[100] = "";
		recv(client_sd, buffer, 100, 0);
		printf("Server response: %s\n", buffer);
		if(strcmp(buffer, "Authenticated successfully") == 0)
		{
			//Wait for calculation
			int result = -1;
			recv(client_sd, &result, sizeof(int), 0);
			printf("%d + %d = %d\n", nums[0], nums[1], result);
		}
	}

}
