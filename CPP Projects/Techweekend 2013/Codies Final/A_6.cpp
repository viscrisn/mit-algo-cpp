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
    int xa_1,xa_2,ya_1,ya_2;
    int xb_1,xb_2,yb_1,yb_2;

    cin>>xa_1>>xa_2>>ya_1>>ya_2;
    cin>>xb_1>>xb_2>>yb_1>>yb_2;

    if(xa_1>xb_1 &&xa_2<<xb_2)
    {
        cout<<"Overlapping\n";
    }
    cout<<"Not overlapping\n";
}
