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
	char a[10];
	char b[10] = "WBWBWBWB";
	char c[10] = "BWBWBWBW";
	int flag = 0;
	for (int i=0;i<8;i++ )
	{
		cin>>a;
        if(strcmp(a,b)!=0)
            if(strcmp(a,c)!=0)
                flag = 1;
	}
	if(flag == 1)
        cout<<"NO";
    else
        cout<<"YES";

}
