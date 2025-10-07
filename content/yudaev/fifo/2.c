#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
	char name[] = "/tmp/myfifo";
	int size;
	(void)umask(0);/*
	if (mknod(name, S_IFIFO|0666,0)<0)
	{
		printf("error fifo\n");
		exit(-1);
	}*/
	int fd = open(name, O_WRONLY);
	char s; 
	while(1)
	{
		scanf("%c",&s);
		//fprintf(stderr, "%c", s);
		switch (s)
		{
			case 'q': {exit(0); break;}
			case 'w': {printf("hello\n"); break;}
			default: {}
		}


		if ((fd=open(name, O_WRONLY))<0)
		{
			printf("feiled to open fifo for writing\n");
			exit(-3);
		}
		size = write(fd, &s,1);
		//fflush(fd);
		if (size!=1)
		{
			printf("cannot write all string\n");
			exit(-4);
		}
		/* --------------------- */

	}
	close(fd);
	return 0;
}