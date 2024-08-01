#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define WRITE_ERROR -3
#define MALLOC_ERROR -2

int main(int argc, char *argv[])
{
	int row = 0;
	int column = 0;
	row = atoi(argv[1]);
	column = atoi(argv[2]);

	//new pipe
	int fd[2];
	if(pipe(fd) == -1){
		printf("Error creating pipe!\n");
		return 1;
	}

	int *A = (int *) malloc((row * column) * sizeof(int)); 
	int i, j;
	printf("Enter the matrix elements:\n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			printf("A[%d,%d] = ", i, j);
			scanf("%d", A + i * column + j);//matrix elements is stored in row-wise
		}
		printf("\n");
	}

	int n = 0;
	printf("Enter a number:");
	scanf("%d", &n);

    //i=1;
    //j=0;
	//printf("%d\n", *(A + i * column + j)); // = 4
	for(int i = 0; i < column; ++i){
		pid_t pid = fork(); // new child
		if (pid == -1){ //not able to create child
			printf("Error creating child!\n");
			return 1;
		}
		else if (pid == 0) {//child
			if(i > 0){	//read previous matrix from previous child and create new one
				printf("child%d PID: %d \n", i, getpid());
				int *A_new = (int *) malloc((row * column) * sizeof(int));
				if(A_new == NULL)
					exit(-3);

				read(fd[0], A_new, (row * column) * sizeof(int));
				for (j = 0; j < row; j++) {
                    *(A_new + j * column + i) = n * (*(A_new + j * column + i));
                    printf("%d * A[%d,%d] = %d\n", n, j, i, *(A_new + j * column + i));
				}

				int bytes_written = write(fd[1], A_new, (row * column) * sizeof(int));
				if(bytes_written < (row * column) * sizeof(int))
					exit(-2); //error writing to pipe

				free(A_new); //freedom
			}
			else{
				printf("child%d PID: %d \n", i, getpid());
				for (j = 0; j < row; j++) {
                    *(A + j * column + i) = n * (*(A + j * column + i));
					printf("%d * A[%d,%d] = %d\n", n, j, i, *(A + j * column + i));
				}

				int bytes_written = write(fd[1], A, (row * column) * sizeof(int));
				if(bytes_written < (row * column) * sizeof(int))
					exit(-2); //error writing to pipe

			}

            close(fd[0]);
            close(fd[1]);
			exit(0);
		}
	}

    int ret;
	while(wait(&ret) != -1){ //wait for all children
		if(WEXITSTATUS(ret) == (256 + WRITE_ERROR)){
			printf("Child exited with status %d (error writing to pipe)\n", WEXITSTATUS(ret) - 256);
			return 3;
		}

		if(WEXITSTATUS(ret) == (256 + MALLOC_ERROR)){
			printf("Child exited with status %d (error allocating memory for new matrix)\n", WEXITSTATUS(ret) - 256);
			return 3;
		}

		//printf("Ret: %d\tWEXITSTATUS: %d\n", ret, WEXITSTATUS(ret) );
	}

	printf("Final matrix elements:\n");
	int *A_new = (int *) malloc((row * column) * sizeof(int));
	if(A_new == NULL){
		printf("Error, parent could not allocate memory to read from pipe\n");
		return 2;
	}

	//Have to read # of row times and then put the matrix together
	read(fd[0], A_new, (row * column) * sizeof(int));

	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			printf("A[%d,%d] = %d\n", i, j, *(A_new + i * column + j));
		}
		printf("\n");
	}

	free(A_new);
	free(A);
	exit(0);
}


//THe issue here is that the variables are set by child and therefore local to child so once operations are done
//AKA the *A references different memory addresses (since it's an array)
//the parents vars stay the same as they were initialized or set to