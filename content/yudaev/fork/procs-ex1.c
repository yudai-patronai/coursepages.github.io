#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ncurses.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	int pid = fork();
	if (pid == -1) exit(-1);
	
	else if (pid == 0)
	{
		char a = fgetc(stdin);
		switch (a)
		{
			case 'q': {exit(0); break;}
			case 'w': {printf("hi \n"); break;}
		}
	} else {
		wait(NULL);
		printf("returned to parent\n");
	}
	return 0;
}