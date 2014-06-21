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
    int test;
    cin>>test;

    for(int testno = 0; testno < test ; testno++ )
    {
        int n;
        cin>>n;
        int a[n];
        for(int i =0; i<n; i++) cin>>a[i];
        int k;
        cin>>k;
        int uncle = a[k-1];
        sort(a,a+n);
        int *pos = find(a,a+n,uncle);
        cout<<(pos - a + 1)<<"\n";

    }
}
