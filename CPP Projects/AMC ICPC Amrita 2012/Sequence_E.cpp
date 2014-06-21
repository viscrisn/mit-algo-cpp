#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>

using namespace std;

int main()
{
    int test_cases;
    cin>>test_cases;

	for (int test_no=0;test_no<test_cases;test_no++ )
	{
        int N;
        cin>>N;

        char S[N+1];
        cin>>S;

        int Q;
        cin>>Q;

        for (int q_no=0;q_no<Q;q_no++ )
        {
        	int a=0,b=0;
        	cin>>a>>b;

        	int parity=0;
        	int ans=0;
        	int temp = 0;
        	for (int i=a-1;i<=b-1;i++ )
        	{
        		if(S[i] == '1')
        		{
        			parity=1;
        			temp =0;
        		}
        		if(parity ==0)
        		{
        		    ans++;
        		}
        		else if(S[i] == '1')
        		{
        		    ans++;
        		}
        		else if(S[i]=='0' && parity == 1)
        		{
        		    temp++;
        		    if(temp>ans)
        		    {
        		        ans = temp;
        		    }
        		}
        	}
        	cout<<ans<<"\n";

        }


	}

}
