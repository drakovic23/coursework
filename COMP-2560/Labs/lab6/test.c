#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


void main()
{
	char str1[20] = "Test\n";

	printf("Len of str1 is: %zu\n", strlen(str1));

	int index = 0;

	while(str1[index])
		index++;

	printf("Len of str1 is: %d\n", index);
}
