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
	char pathname[] = "sender.c";
	key_t key;
	int i, len;
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

	/*if everything coped  - sending mesages into queue with msgid ==1*/
	for (i=0;i<3;++i)
	{
		mybuf.mtype = 1;
		strcpy(mybuf.mtext, "greeting");
		len = strlen(mybuf.mtext)+1;
		if (msgsnd(msgid, (struct buff *) &mybuf, len,0)<0)
		{
			printf("failed sending message");
			msgctl(msgid,IPC_RMID, (struct msqid_ds *)  NULL);
			exit(-4);
		}
	}
	mybuf.mtype = LASTMESSAGE;
	len = 0;
	if(msgsnd(msgid, (struct buff *)&mybuf, len,0)<0)
	{
		printf("failed sending last message\n");
		msgctl(msgid, IPC_RMID, (struct msqid_ds *) NULL);
		exit(-5);
	}
	
	return 0;
}
