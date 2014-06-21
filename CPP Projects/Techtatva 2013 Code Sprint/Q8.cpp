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

int isprime(int n)
{
    for (int i=2;i<=n/2;i++ )
    {
    	if(n%i==0)
            return -1;
    }
    return 1;

}
int main()
{
    int arr[100000] = {0};
    for (int i=2; i<100000; i++ )
    {
        if(isprime(i)==1)
        {
            arr[i] = 1;
        }
    }

    int n;
    cin>>n;

    for (int i=1; i<n; i++ )
    {
        if(arr[i]==0)
            continue;
        for (int j=1; j<n; j++ )
        {
            if(arr[j]==0)
                continue;
            for (int k=1; k<n; k++ )
            {
                if(arr[k]==0)
                    continue;
                for (int t=0; t<n; t++ )
                {
                    if(arr[t]==0)
                        continue;

                    if(i+j+k+t == n)
                    {
                        cout<<i<<" "<<j<<" "<<k<<" "<<t;
                        return 0;
                    }
                }

            }

        }

    }


}
