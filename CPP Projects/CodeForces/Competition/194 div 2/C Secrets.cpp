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
    long long n;
    cin>>n;
    long long a[20];
    a[0] = 1;
    for (int i=1; i<20; i++ )
    {
        a[i] = a[i-1] * 3;
    }
    int i;
    for ( i=0;i<20;i++ )
    {
    	if(n%a[i] != 0)
            break;
    }
    cout<<((n/a[i])+1);

}
