#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<functional>

using namespace std;

int main()
{
    char str[103];
    cin>>str;
    int len = strlen(str);
    if(len == 1)
    {
        if(isupper(str[0]))
            cout<<(char)tolower(str[0]);
        else
            cout<<(char)str[0];
        return 0;
    }
    if(isupper(str[0])&&isupper(str[1]))
    {
        cout<<str[0];
        for (int i=1; i<len; i++)
        {
            cout<<(char)tolower(str[i]);
        }
    }
    else if(isupper(str[0])&&isupper(str[1]))

}
