#include <fcntl.h>
#include <unistd.h>
//Had to use this or I always got junk characters in log.txt using sizeof
int stringlen(char str[])
{
	int len = 0;
	while(str[len])
		len++;

	return len;
}

int main()
{
	int fd_wr = open("./log.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	
	char error_open[20] = "Error opening file\n";
	if(fd_wr == -1)
		write(STDOUT_FILENO, error_open, sizeof(error_open));
	

	char buf[20];
	ssize_t bytes_read;
	
	while((bytes_read = read(STDIN_FILENO, buf, sizeof(buf))) > 0)
	{
		if(buf[0] == 'E' && buf[1] == 'N' && buf[2] == 'D' && buf[3] == '\n')
		{
			int ret = close(fd_wr);
			char error_close[30] = "Error in closing device\n";
			if(ret == -1)
				write(STDOUT_FILENO, error_close, sizeof(error_close));

			break;
		}

		write(fd_wr, buf, stringlen(buf));

		//Clear buffer
		int index = 0;
		while(buf[index])
		{
			buf[index] = '\0';
			index++;
		}
	}
	
	
	char error_read[30] = "Error reading from device\n";
	if(bytes_read == -1)
	{
		write(STDOUT_FILENO, error_read, sizeof(error_read));

		char error_close[30] = "Error in closing device\n";
		int ret = close(fd_wr);
		if(ret == -1)
			write(STDOUT_FILENO, error_close, sizeof(error_close));
	}
	
	return 0;
}
