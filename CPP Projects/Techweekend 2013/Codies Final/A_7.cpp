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
    int n;
    cin>>n;

    while(n!=1)
    {
        if(n%2!=0)
        {
            cout<<"NO";
            return 0;
        }
        n/=2;

    }
    cout<<"YES";


}
