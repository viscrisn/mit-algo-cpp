#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* shifttable (char pattern[], int n)
{
	int *table=new int[26];
	int i, pos;
	for (i=0;i<26;i++)
	{
		table[i]=n;
	}
	for (i=0;i<n-1;i++)
	{
		pos=(int)(pattern[i]-65);
		table[pos] = n-1-i;
	}
	for (i=0;i<26;i++)
		printf("%d ",table[i]);
	return table;
}

void horspool (char string[100], char pattern[100], int *table)
{
	int i,j,k=0,pos,f=0;
	int index = strlen(pattern)-1;
	for (i=0;i<strlen(string);i++)
	{
		k=0;
		printf("index = %d\n",index);
		for (j=strlen(pattern)-1; j>=0; j--)
		{
			if (pattern[j] != string[index])
			{
				pos = (int)string[index]-65;
				index += table[pos];
				break;
			}
			else
			{k++;index--;}
		}

		if (k == strlen(pattern))
		{
			f=1;
			break;
		}
	}
	if (f==1)
		printf("Substring Found\n");
	else
		printf("Not Found\n");
}

int main ()
{
	char string[100], pattern[100];
	int *table;
	//clrscr();
    scanf("%s",string);
    scanf("%s",pattern);
	table = shifttable (pattern, strlen(pattern));
	printf("\n");
	horspool(string,pattern,table);
	return 0;
	//getch();
}


