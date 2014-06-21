#include<stdio.h>
#include<conio.h>
#include<string.h>

int StringMatching(char text[100],char pattern[100])
{
	int i,j,n,m;
	n=strlen(text);
	m=strlen(pattern);
	for(i=0;i<n-m+1;i++)
	{
		j=0;
		while(j<m && pattern[j]==text[i+j])
		{
			j=j+1;
		}
		if(j==m)
			return i;
	}
	return -1;
}

void main()
{
	char text[100],pattern[100];
	int f;
	clrscr();
	printf("Enter the text string (Give _ in place of space) :-  ");
	scanf("%s",&text);
	flushall();
	printf("Enter the pattern string (Give _ in place of space) :-  ");
	scanf("%s",&pattern);
	flushall();
	f=StringMatching(text,pattern);
	if(f>=0)
		printf("\nPattern found 1st at %d",(f+1));
	else
		printf("\nPattern Not Found");
	getch();
}