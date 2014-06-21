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

struct box
{
    long long q;
    int i,k;
    bool f;
}b[110000];

bool cmp(box c,box d)
{
    if(c.k != d.k)
        return c.k > d.k;
    return c.q > d.q;
}

int main()
{
	freopen("exact.in","r",stdin);
	freopen("exact.out","w",stdout);

	long long x,n;
	cin>>x>>n;
	for (int i=0;i<n;i++ )
	{
		cin>>b[i].k>>b[i].q;
		b[i].i = i+1;
		b[i].f = false;
	}
	sort(b,b+n,cmp);

    /*
	for (int i=0;i<n;i++ )
	{
		cout<<b[i].k<<" "<<b[i].q<<"\n";
	}
	*/

	int sum =0;
	int counter =0;
	int c=0;
	while((sum < x)&&(counter<n))
	{
	    while(b[counter].q>0)
	    {
	        if(sum + pow(10,b[counter].k)<=x)
	        {
	            if(b[counter].f == false)
	            {
	                b[counter].f = true;
	                c++;
	            }

	            sum += pow(10,b[counter].k);
	            b[counter].q --;
	        }
	        else
                break;
	    }
	    counter++;
	}
	if(sum != x)
	{
	    cout<<-1;
	    return 0;
	}

	cout<<c<<"\n";
    for (int i=0;i<n;i++ )
    {
        if(b[i].f==true)
            cout<<b[i].i<<" ";
    }
    return 0;

}
