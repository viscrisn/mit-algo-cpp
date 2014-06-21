#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int test;
	cin>>test;
	for (int test_no=0;test_no<test;test_no++)
	{
		char str[103];
		cin>>str;
		int len;
		len = strlen(str);

		if(len<=10)
		{
		    cout<<str<<"\n";
		}
		else
		{
		    cout<<str[0]<<len -2<<str[len - 1]<<"\n";
		}
	}
	return 0;
}
