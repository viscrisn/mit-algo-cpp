#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	pid=fork();
	printf("PID :- %d",pid);
	if(pid<0)
	{
		printf("Error");
		return -1;
	}
	else if(pid==0)
	{
		printf("Parent ID :- %d",getpid());
	}
	else
	{
		printf("\nChild Process\n");
		printf("Parent ID :- %d\nChild ID :- %d",getppid(),getpid());
	}
}
