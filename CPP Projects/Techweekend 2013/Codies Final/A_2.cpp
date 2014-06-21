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

void loop(int n)
{
    if(n==0)
    {
        return;
    }
    else
    {
        cout<<n<<"\n";
        loop(n-1);
    }
}
int main()
{
    loop(100);
}
