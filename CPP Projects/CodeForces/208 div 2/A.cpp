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
    int n;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++ )
    {
        cin>>a[i];
    }
    bool flag = false;

    for (int i=0;i<n-1;i++ )
    {
        int x1 = a[i];
        int x2 = a[i+1];
        if(x1 > x2)
            swap(x1,x2);
        for (int j=0;j<n-1;j++ )
        {
            int y1 = a[j];
            int y2 = a[j+1];
            if(y1 > y2)
                swap(y1, y2);
            if(x1 == y1 && x2 == y2)
                continue;
        	if(x1 <= y1 && x2 >= y1 && x2 <= y2)
        	{
        	    flag = true;
        	    break;
        	}
        	if(x1 >= y1 && x1 <= y2 && x2 >= y2)
        	{
        	    flag = true;
        	    break;
        	}
        }
        if(flag == true)
            break;
    }

    if(flag == true)
        cout<<"yes";
    else
        cout<<"no";

}
