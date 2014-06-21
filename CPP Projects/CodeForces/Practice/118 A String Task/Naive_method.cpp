#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;

bool isvowel(char a)
{
    if(a=='A'||a=='E'||a=='I'||a=='O'
       ||a=='U'||a=='a'||a=='e'
       ||a=='i'||a=='o'||a=='u'||a=='y'||a=='Y')
       {
           return true;
       }
       return false;
}
int main()
{
	char str[103];
	cin>>str;
	int len = strlen(str);
	for (int i=0;i<len;i++)
	{
	    if(isvowel(str[i]))
            continue;
        if(isupper(str[i]))
            cout<<"."<<(char)tolower(str[i]);
        else
            cout<<"."<<(char)str[i];
	}
}
