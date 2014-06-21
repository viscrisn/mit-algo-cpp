#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdio.h>

using namespace std;

bool check_unique(char *str)
{
	int len_str = strlen(str);
	sort(str,str+len_str);
	for(int i =1;i<len_str;i++)
	{
		if(str[i] == str[i-1])
			return false;
	}
	return true;
}

int main()
{
	char str[1000];
	gets(str);
	if(check_unique(str) == true)
		cout<<"Yes, they are unique";
	else
		cout<<"No, they are not unique";

	return 0;
}
