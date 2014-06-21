#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <map>

#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int maxn = 1000 * 100 + 5;

int n, q;
LL arr[maxn];
LL sum[maxn];
LL ans[maxn];


LL solve(LL k)
{
    LL i = n - 1;
    LL z = 1;
    LL zi = 0;
    LL res = 0;
    while (i >= 0)
    {
        LL nxt = i - z;
        res += (sum[i] - (nxt >= 0 ? sum[nxt] : 0)) * zi;
        zi++;
        z *= k;
        i = nxt;
    }
    return res;
}

int main()
{
    int test;
    cin>>test;

    for(int testno = 0; testno < test ; testno++ )
    {
        vector <LL> que;

        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n);
        sum[0] = arr[0];
        for (int i = 1; i < n; i++)
            sum[i] = arr[i] + sum[i - 1];

        cin >> q;
        for (int i = 0; i < maxn; i++)
            ans[i] = -1;
        que.resize(q);
        for (int i = 0; i < q; i++)
        {
            cin >> que[i];
            if (ans[que[i]] == -1)
                ans[que[i]] = solve(que[i]);
        }

        for (int i = 0; i < q; i++)
            cout << ans[que[i]] << " ";
        cout << endl;

    }
}

