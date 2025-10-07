#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define LASTMESSAGE (255)
#define MAXTEXT (20)

int main()
{
	int msgid;
	char  pathname[] = "sender.c";
	key_t key;
	int i, len, maxlen;
	struct buff
	{
		int mtype;
		char mtext[MAXTEXT];
	} mybuf;

	if ((key = ftok(pathname,0))<0)
	{
		printf("cannot create message queue\n");
		exit(-1);
	}
	if ((msgid = msgget(key, 0666|IPC_CREAT))<0)
	{
		printf("cannot access mes queue\n");
		exit(-2);
	}

	/*if ok  - eternally receiveing messages with type ==1 */
	while (1)
	{
		maxlen = 20;

		if (len = msgrcv(msgid, (struct buff *) &mybuf, maxlen,0,0)<0)
		{
			printf("failed receiving message");
			
			exit(-6);
		}
		if (mybuf.mtype == LASTMESSAGE)
		{
			msgctl(msgid, IPC_RMID, (struct msqid_ds *) NULL); //delete message queue
			exit(0);
		}
		printf("message type = %d, info = %s\n",mybuf.mtype, mybuf.mtext);
	}
	return 0;
}
