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
    int y,k,n;
    cin>>y>>k>>n;
    if(n-y < 0)
    {
        printf("-1");
        return 0;
    }
    int flag = 0;
    int i2 =0;
    for (int i=k;i<n-y;i++ )
    {
    	if((i+y)%k==0)
        {
            i2 = i;
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("-1");
        return 0;
    }

    for (int i=i2; i<= n-y; i+=k )
    {
        if((i+y)%k==0)
        {
            printf("%d ",i);
        }
    }


}
