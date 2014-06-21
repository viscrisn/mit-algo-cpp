#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>


using namespace std;

int main ()
{

    int n, m;
    cin >> n >> m;

    vector<int> a(n), inc(n), dec(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 1; i < n; i++)
    {
        inc[i] = (a[i] >= a[i-1]) ? inc[i-1] : i;
        dec[i] = (a[i] <= a[i-1]) ? dec[i-1] : i;
    }

    for(int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if(inc[dec[r]] == inc[l] || dec[r] == dec[l])
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
