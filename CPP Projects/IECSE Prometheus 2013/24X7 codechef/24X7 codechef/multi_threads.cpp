#include <iostream>

using namespace std;

int a[100000];

int main()
{
    int test;
    cin>>test;

    for(int testno = 0; testno < test ; testno++ )
    {
        int n,ans=0;
        cin >> n;
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=n-1; i-1>=0; i--)
        {
            if(a[i]<a[i-1]) break;
            ans++;
        }
        cout << n-ans-1<<"\n";
    }

}
