#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("\nProcess %d is about to execute as ls -l\n",getpid());
	execl("/bin/ls","ls","-l",NULL);
}
