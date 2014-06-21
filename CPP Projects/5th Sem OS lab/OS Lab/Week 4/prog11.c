#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1,fd2,rd,wr;
	char  buf[50];
	fd1=open("file11.txt",O_RDWR,0755);
	fd2=open("file12.txt",O_CREAT|O_RDWR,0755);
	if(fd1!=-1 && fd2!=-1)
	{
		rd=read(fd1,buf,49);
		if(rd!=-1)
		{
			wr=write(fd2,buf,49);
		}
		else
		{
			printf("Could Not Write");
		}
	}
	else
	{
		printf("Could Not Read");
	}
	rd=close(fd1);
	wr=close(fd2);
}

