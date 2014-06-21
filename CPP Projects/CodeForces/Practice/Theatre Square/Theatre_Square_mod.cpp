#include<iostream>
#include<cmath>

using namespace std;

//working
int main()
{
	long long n,m,a;
	cin>>n>>m>>a;
	long long hor = n/a;
	if(n%a!=0) hor++;
	long long ver = m/a;
	if(m%a!=0) ver++;
	cout<<hor * ver;
}
