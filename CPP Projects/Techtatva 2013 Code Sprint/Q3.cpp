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

int main()
{
    char a[100];
    cin>>a;
    char b[100];
    int count = 0;
    for (int i=0; i<strlen(a); i++ )
    {
        b[count++] = a[i];
    }
    for (int i=0; i<strlen(a); i++ )
    {
        b[count++] = a[i];
    }
    b[count] = '\n';
    //cout<<b;
    int direction;
    cin>>direction;

    int rot;
    cin>>rot;

    if(direction == 0)
    {
        for (int i=rot; i<strlen(a)+rot; i++ )
        {
            cout<<b[i];
        }
    }
    else
    {
        rot = strlen(a)-rot;
        for (int i=rot; i<strlen(a)+rot; i++ )
        {
            cout<<b[i];
        }
    }

}
