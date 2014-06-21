#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int test;
    cin>>test;

    while (test>0)
    {
        test--;
        char a[1001];

        cin>>a;
        int len = strlen(a);
        int max_length = len * 11;
        int diff=0;
        int count = 2;

        for (int i=0;i<len-1;i++ )
        {
        	diff = a[i+1] - a[i];
        	if(diff<0)
        	{
        	    count += 26+diff;
        	}
        	else
        	{
        	    count += diff;
        	}
        }
        count += len-1;

        if(count <= max_length)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }


    }
}
