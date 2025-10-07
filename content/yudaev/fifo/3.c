#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char * argv[], char * envp[])
{
	char s;
	int size;
	/*
	int num = fork();
	if (num<0) exit(-2);
	if (num==0) (void)execl("2.exe","2.exe", argv,0);
	else */
	{
		char name[] = "/tmp/myfifo";
		/*
		(void)umask(0);
		if (mknod(name, S_IFIFO|0666,0)<0)
		{
			printf("error fifo\n");
			exit(-1);
		}*/
		int fd;
		if ((fd = open(name, O_RDONLY))<0) 
			{
				printf("Parent: cannot read fifo\n");
				exit(-3);
			}
		size = read(fd,&s,1);
		//mes[5] = 0;

		/* in case of fail */
		if(size<0)
		{
			printf("child process, failed to read\n");
			exit(-6);
		}
		/* --------------------- */
		printf("Parent: %c",s);


	}
	/*printf("exit on bad start\n");
	exit(-1); */
	return 0;
}