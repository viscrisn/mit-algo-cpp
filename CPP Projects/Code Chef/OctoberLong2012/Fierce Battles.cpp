#include<iostream>
#include<stdlib.h>
#include<cmath>

using namespace std;

int main()
{
	int test;
	cin>>test;

	while(test)
	{
	    test--;
	    int N,M;
	    cin>>N>>M;
	    int soints[N][2];
	    int sofloats[M][2];
        int* power = (int*)(calloc(101,sizeof(int)));
	    for (int i=0;i<N;i++ )
	    {
            cin>>soints[i][0]>>soints[i][1];
            power[soints[i][1]] += soints[i][0];
	    }
	    for (int i=0;i<M;i++ )
	    {
            cin>>sofloats[i][0]>>sofloats[i][1];
            power[sofloats[i][1]] -= sofloats[i][0];
	    }
	    int ans=0;
	    int temp;
        for (int i=0;i<101;i++)
        {
        	if((temp = power[i])<0)
        	{
        	    ans += abs(temp);
        	}
        }
        cout<<ans;
        free(power);

	}
}
