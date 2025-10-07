#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int fd, res;
	size_t size;
	char mes[6];
	char fifoname[] = "1.fifo";

	(void) umask(0);
	if (mknod(fifoname, S_IFIFO|0666,0)<0)
	{
		printf("can\'t create fifo\n");
		exit(-1);
	}
	if ((res=fork())<0)
	{
		printf("cannot fork \n");
		exit(-2);
	}
	else if (res>0)
	{
		printf("Parent porocess. Opening fifo for writing. \n");

		/* in cases of fail*/
		if ((fd=open(fifoname, O_WRONLY))<0)
		{
			printf("feiled to open fifo for writing\n");
			exit(-3);
		}
		size = write(fd, "Hello",6);
		//fflush(fd);
		if (size!=6)
		{
			printf("cannot write all string\n");
			exit(-4);
		}
		/* --------------------- */
		close(fd);

	}
	else if (res==0)
	{
		printf("child process, open fifo for reading\n");
		if ((fd=open(fifoname,O_RDONLY))<0)
		{
			printf("cannot open fifo for reading\n");
			exit(-5);
		}
		size = read(fd,mes,6);
		mes[5] = 0;

		/* in case of fail */
		if(size<0)
		{
			printf("child process, failed to read\n");
			exit(-6);
		}
		/* --------------------- */

		printf("child process, printing message: \t%s \n", mes);
		close(fd);
		system("rm 1.fifo"); //deleting unused file
	}

	//system("rm 1.fifo");
	return 0;
}