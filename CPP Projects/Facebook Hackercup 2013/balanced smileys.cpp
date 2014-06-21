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
#include<queue>

using namespace std;

int main()
{
    int test;
    cin>>test;
    getchar();
    for(int testno = 0; testno < test ; testno++ )
    {
        char s[510];
        cin.getline(s,510,'\n');
        int len = strlen(s);

        int minopen=0,maxopen=0;
        if(s[0]=='(')
        {
            maxopen++;
            minopen++;
        }
        else if(s[0]==')')
        {
            cout<<"Case #"<<testno+1<<": NO\n";
            continue;
        }
        for (int i=1; i<len; i++ )
        {
            if((s[i]=='(')&&(s[i-1]==':'))
            {
                maxopen++;
            }
            else if((s[i]=='(')&&(s[i-1]!=':'))
            {
                maxopen++;
                minopen++;
            }
            else if((s[i]==')')&&(s[i-1]==':'))
            {
                minopen--;
            }
            else if((s[i]==')')&&(s[i-1]!=':'))
            {
                minopen--;
                maxopen--;
            }
            if(minopen<0)
            {
                minopen = 0;
            }
        }
        if((maxopen<0)||minopen!=0)
        {
            cout<<"Case #"<<testno+1<<": NO\n";
        }
        else
        {
            cout<<"Case #"<<testno+1<<": YES\n";
        }

    }

}
