#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<functional>
#include<stack>
#include<set>
#include<queue>
#include<fstream>

using namespace std;

char * longest_substr_conti(char *str)
{
    int max_i =0,cur_i =0;
    int len_max = 0,len_cur = 0,len_str = strlen(str);
    for (int i=0;i<len_str-1;i++ )
    {
    	if(str[i] == (str[i+1]-1)||
        str[i]==(str[i+1]+1))
    	{
    	    len_cur++;
    	}
    	else
    	{
    	    if(len_cur>len_max)
    	    {
    	        len_max = len_cur;
    	        max_i = cur_i;
    	    }
            len_cur = 0;
            cur_i = i;
    	}
    }
    str[max_i + len_max+1] = '\0';
    return (str+max_i+1);
}
int main()
{
	char buf[100];
	cin>>buf;
    cout<<longest_substr_conti(buf);
}
