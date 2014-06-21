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
    char a[100];

    cin>>a;
    int n = strlen(a);

    reverse(a,a+n);
    cout<<a<<" ";

    if(a[n])
    cin>>a;
    n = strlen(a);

    reverse(a,a+n);
    cout<<a;
}
