#include<iostream>
#include<string.h>
using namespace std;
void print(int curr,int n, char*s,int b)
{
	if(curr!=n)
	{
	if(b==0)
		s[curr]='F';
	else
		s[curr]='T';

		print(curr+1,n,s,0);
		print(curr+1,n,s,1);
	}
	else
	{
		s[curr]='\0';
		if(b==0)
		cout<<s<<endl;
	}
}

int main()
{
	int n;
	cin>>n;
	int curr=0;
	char s[10];
	strcpy(s,"");
	int b=0;
	print(curr,n,s,b);
	strcpy(s,"");
	b=1;
	print(curr,n,s,b);
}

