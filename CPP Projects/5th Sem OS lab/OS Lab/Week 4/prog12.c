#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1,fd2,rd,wr;
	long offset;
	char buf[20];
	fd1=open("file11.txt",O_RDONLY,0600);
	offset=lseek(fd1,0,SEEK_END);
	fd2=open("file122.txt",O_CREAT|O_RDWR,0775);
	if(fd1!=-1 && fd2!=-1)
	{
		rd=read(fd1,buf,20);
		if(rd!=-1)
		{
			wr=write(fd2,buf,20);
		}
	}
}
