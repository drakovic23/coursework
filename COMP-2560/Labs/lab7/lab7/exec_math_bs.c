#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

	printf("exec_math_bs pid:%d\n", getpid());

	int child_pid = fork();
	if(child_pid == -1)
	{
		perror("Error creating child process\n");
		exit(3);
	}

	if(child_pid >= 0)
	{
		if(child_pid > 0) //parent
		{
			//Wait for child to compile
			int ret = wait(NULL);
			if(ret < 0)
			{
				printf("Error waiting for child!\n");
				exit(6);
			}
			int fd_math = open("./main_add", O_RDONLY);
			char *math_argv[] = {"./main_add", argv[2], argv[3], NULL};
			char *newenviron[] = {NULL};

			int res = fexecve(fd_math, math_argv, newenviron);
			if(res < 0)
			{
				printf("Error executing ./main_add\n");
				exit(5);
			}
		}
		else //child
		{

			//int child_pid = getpid();
			//printf("Child PID: %d\n", child_pid);
			int fd = creat("./math.c", S_IRUSR | S_IWUSR);
			printf("fd for math.c file: %d\n", fd);
			if(fd < 0)
			{
				printf("Error creating C file!\n");
				exit(2);
			}
			//printf("Arv[1]: %s\n", argv[1]);
			if(strcmp(argv[1],"+") == 0)
			{
				char *program = "#include <stdio.h>\n"
								"#include <stdlib.h>\n"
								"#include <unistd.h>\n"
								"int result;\n"
								"int main(int argc, char *argv[]){\n"
								"printf(\"math pid: %d\\n\", getpid());\n"
								"int a = 0;\n"
								"int b = 0;\n"
								"a = atoi(argv[1]);\n"
								"b = atoi(argv[2]);\n"
								"result = a + b;\n"
								"printf(\"%d + %d = %d\\n\", a, b, result);\n"
								"return 0;\n"
								"}\n";
				write(fd, program, strlen(program));
			}
			else if(strcmp(argv[1],"-") == 0)
			{
				char *program = "#include <stdio.h>\n"
								"#include <stdlib.h>\n"
								"#include <unistd.h>\n"
								"int result;\n"
								"int main(int argc, char *argv[]){\n"
								"printf(\"math pid: %d\\n\", getpid());\n"
								"int a = 0;\n"
								"int b = 0;\n"
								"a = atoi(argv[1]);\n"
								"b = atoi(argv[2]);\n"
								"result = a - b;\n"
								"printf(\"%d - %d = %d\\n\", a, b, result);\n"
								"return 0;\n"
								"}\n";
				write(fd, program, strlen(program));
			}
			else if(strcmp(argv[1],"*") == 0)
			{
				char *program = "#include <stdio.h>\n"
								"#include <stdlib.h>\n"
								"#include <unistd.h>\n"
								"int result;\n"
								"int main(int argc, char *argv[]){\n"
								"printf(\"math pid: %d\\n\", getpid());\n"
								"int a = 0;\n"
								"int b = 0;\n"
								"a = atoi(argv[1]);\n"
								"b = atoi(argv[2]);\n"
								"result = a * b;\n"
								"printf(\"%d * %d = %d\\n\", a, b, result);\n"
								"return 0;\n"
								"}\n";
				write(fd, program, strlen(program));
			}
			else if(strcmp(argv[1],"/") == 0)
			{
				char *program = "#include <stdio.h>\n"
								"#include <stdlib.h>\n"
								"#include <unistd.h>\n"
								"int result;\n"
								"int main(int argc, char *argv[]){\n"
								"printf(\"math pid: %d\\n\", getpid());\n"
								"int a = 0;\n"
								"int b = 0;\n"
								"a = atoi(argv[1]);\n"
								"b = atoi(argv[2]);\n"
								"result = a / b;\n"
								"printf(\"%d / %d = %d\\n\", a, b, result);\n"
								"return 0;\n"
								"}\n";
				write(fd, program, strlen(program));
			}
			else
			{
				printf("Error reading argv[1] or invalid argument passed\n");
				exit(1);
			}

			//close fd var and reuse
			close(fd);
			fd = open("/usr/bin/cc", O_RDONLY);
			//Setup args for cc and exec
			char *newargv[] = {"cc", "./math.c", "-o", "main_add", NULL};
			extern char** environ;
			int res = fexecve(fd, newargv, environ);
			if(res < 0)
			{
				printf("Error executing cc\n");
				exit(4);
			}

			close(fd);
		}
	}

	return 0;
}
