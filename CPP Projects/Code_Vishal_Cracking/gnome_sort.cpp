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

void gnome_sort(int a[],int n)
{
    int pos = 1;
    while (pos < n)
    {
        if (a[pos] >= a[pos-1])
            pos = pos + 1;
        else
        {
            swap(a[pos],a[pos-1]);
            if (pos > 1)
                pos = pos - 1;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    gnome_sort(a,n);

    for (int i=0; i<n; i++ )
    {
        cout<<a[i]<<"\t";
    }
    return 0;

}
