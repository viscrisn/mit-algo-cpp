#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int status,childpid,pid;
	pid=fork();
	printf("PID :- %d",pid);
	if(pid!=0)
	{
		printf("%d %d",getpid(),getppid());
		childpid=wait(&status);
		printf("Child With PID %d terminated with exit code %d",childpid,status>>8);
	}
	else
	{
		printf("Child With PID %d terminated with exit code %d",childpid,status>>8);
		exit(42);
	}
}
