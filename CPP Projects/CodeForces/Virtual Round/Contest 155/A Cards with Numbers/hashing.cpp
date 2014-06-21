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
#include<fstream>

using namespace std;



int main()
{
    int a[5010][2];
    for (int i=0; i<5009; i++ )
    {
        a[i][0] = -1;
        a[i][1] = -1;
    }
    int n;

    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

    cin>>n;
    int two_n;
    two_n = n*2;
    int ans[two_n][2];
    int temp;
    int counter = 0;
    for (int i=1; i<=two_n; i++ )
    {
        cin>>temp;
        if(a[temp][0]==temp)
        {
            ans[counter][0] = a[temp][1];
            ans[counter][1] = i;
            counter++;
            a[temp][0]= -1;
            a[temp][1]= -1;
        }
        else
        {
            a[temp][0] = temp;
            a[temp][1] = i;
        }
    }
    for (int i=0; i<5003; i++ )
    {
        if(a[temp][0]!= -1)
        {
            cout<<-1;
            return 0;
        }
    }
    for (int i=0; i<counter; i++ )
    {
        cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
    }
    return 0;


}
