#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>

using namespace std;

void reverse(char* s)
{
    int len =0;
    while(s[len]!='\0')
    {
        len++;
    }
    for (int i=0;i<len/2;i++ )
    {
    	int temp = s[i];
    	s[i] = s[len -i - 1];
    	s[len - i - 1] = temp;
    }
    s[len] = '\0';
}

int main()
{
	char s[100];
	cin>>s;
	cout<<s<<endl;
	reverse(s);
	cout<<s;
}
