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

int var[26];
char buf[110];

void evaluate(char *buf, int start, int end)
{

}
int main()
{

	cin.getline(buf,101,'\n');
	while(buf[0]!='#')
	{
	    int len = strlen(buf);
	    int ind = 0;
	    for (int i=0;i<len;i++ )
	    {
	    	if(buf[i]==' ')
                continue;
            buf[ind++] = buf[i];
	    }
	    buf[ind] = '\0';
	    len = ind;
	    int temp1=0,temp2=0;
        stack<char> stk;
        for (int i=0;i<len;i++ )
        {
            /*if(buf[i] == ')')
            {
                while(stk.top!='(')
                {

                }
            }*/
        	stk.push(buf[i]);
        }
        while(stk.size()>0)
        {
            char cur = stk.top();
            if(cur >= '0' && cur <='9')
            {
                temp1 = cur - '0';
            }
            if(cur == '_')
                temp1 = -temp1;

            stk.pop();
        }

	    cin.getline(buf,101,'\n');
	}

}
