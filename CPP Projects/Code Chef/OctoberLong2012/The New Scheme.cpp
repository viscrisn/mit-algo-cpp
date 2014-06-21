#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int test;
	cin>>test;

	while(test)
	{
	    test--;

	    int n;
	    cin>>n;
	    if(n==2)
	    {
	        cout<<"12\n";
	        continue;
	    }
	    long long days_mul = 0;
	    days_mul = pow(3,n-2);
	    cout<<8*days_mul;
	}
}
