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

char *base4_base2(char *num)
{
    int len = strlen(num);
    int last = 2*len-1;
    num[last] = '\0';
    for (int i=len-1;i>=0;i-- )
    {
    	if(num[i]=='3')
    	{
    	    num[last--] = '1';
    	    num[last--] = '1';
    	}
    	else if(num[i]=='2')
    	{
    	    num[last--] = '0';
    	    num[last--] = '1';
    	}
    	else if(num[i]=='1')
    	{
    	    num[last--] = '1';
    	    num[last--] = '0';
    	}
    	else if(num[i]=='0')
    	{
    	    num[last--] = '0';
    	    num[last--] = '0';
    	}
    }
    return num;
}

int main()
{
    char buf[100];
    cin>>buf;
    cout<<base4_base2(buf);
}
