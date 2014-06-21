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

long long area(long long up,long long left)
{
    long long lar=0,sml = 0,ul=0;
    if(up==left)
    {
        ul = ((up+1)*up)/2;
    }
    else
    {
        if(up>left)
        {
            lar = up;
            sml = left;
        }
        else
        {
            lar = left;
            sml = up;
        }
        ul = (((lar+1)*lar)/2) - (((sml+1)*sml)/2);
    }
    return ul;
}
int main()
{
    int n,x,y,c;
    cin>>n>>y>>x>>c;
    int cur=1,time = -2;
    if(c==1)
    {
        cout<<0;
        return 0;
    }
    long long up=0,right=0,left=0,down=0,left1=0,down1=0;
    while(cur < c)
    {
        time++;
        if((up+y)<n)
        {
            up++;
        }
        if((down1+y)>1)
        {
            down1--;
        }
        if((right+x)<n)
        {
            right++;
        }
        if((left1+x)>1)
        {
            left1--;
        }
        left = abs(left1);
        down = abs(down1);
        long long ul=0,ur=0,dl=0,dr=0;
        ul = area(down,left);
        ur = area(down,right) - down;
        dl = area(up,left) - left - up + 1;
        dr = area(up, right) - right;
        cur = ul +ur+dl+dr;
    }
    cout<<time;
    return 0;
}
