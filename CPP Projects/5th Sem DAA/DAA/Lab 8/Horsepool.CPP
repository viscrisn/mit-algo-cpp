#include<iostream.h>
#include<conio.h>
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
	//	cout << pos << "\n";
		table[pos] = n-1-i;
	}
	for (i=0;i<26;i++)
		cout << table[i] << " ";
	return table;
}

void horspool (char *string, char *pattern, int *table)
{
	int i,j,k=0,pos,f=0;
	int index = strlen(pattern)-1;
	for (i=0;i<strlen(string);i++)
	{
		k=0;
		cout << "index = " << index <<"\n";
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
		cout << "Substring Found\n";
	else
		cout << "Not Found\n";
}

void main ()
{
	char *string, *pattern;
	int *table,i;
	clrscr();
	cin >> string >> pattern;
	table = shifttable (pattern, strlen(pattern));
	cout << "\n";
	horspool(string,pattern,table);
	getch();
}


