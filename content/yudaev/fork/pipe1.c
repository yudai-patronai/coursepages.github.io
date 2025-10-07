#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int fd[2];
	size_t size;
	char messtring[] = "Happy March, 8th!";
	int l = strlen(messtring);
	char * res = (char*)malloc(sizeof(messtring));

	if (pipe(fd)<0)
	{
		printf("cannot create pipe\n");
		exit(-1);

	}
	size = write(fd[1],messtring, l); //error writing
	if (size!=l)
	{
		printf("didn\'t write whole string\n");
		exit(-2);
	}
	size = read(fd[0],res,l);
	if (size<0) //error reading
	{
		printf("cannot read \n");
		exit(-3);
	}
	printf("%s\n",res);
	if (close(fd[0])<0)
	{
		printf("cannot close input\n");
	}
	if (close(fd[1])<0)
	{
		printf("cannot close output\n");
	}
	return 0;
}
