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

struct point
{
    int x;
    int y;
};

bool comp(point a, point b)
{
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
int main()
{
    point a[8];
    for (int i=0; i<8; i++ )
    {
        cin>>a[i].x;
        cin>>a[i].y;
    }
    sort(a,a+8,comp);
    int x1,x2,x3,y1,y2,y3;
    x1 = a[0].x;
    x2 = a[3].x;
    x3 = a[5].x;
    y1 = a[0].y;
    y2 = a[1].y;
    y3 = a[2].y;

    if(x1 < x2 && x2 < x3 && y1 < y2 && y2 < y3)
    {
        if(x1==a[1].x && x1==a[2].x && x3==a[6].x && x3==a[7].x && x2 == a[4].x)
        {
            if(y1==a[3].y && y1==a[5].y && y2==a[6].y && y3==a[7].y && y3 == a[4].y)
            {
                cout<<"respectable";
                return 0;
            }

        }

    }
    cout<<"ugly";


}
