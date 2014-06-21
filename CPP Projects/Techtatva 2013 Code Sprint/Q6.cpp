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

int main()
{
	int n;
	cin>>n;

	double a[n];
	for (int i=0;i<n;i++ )
	{
		cin>>a[i];
	}
	double sum = 0;
	for (int i=0;i<n;i++ )
	{
		sum+=a[i];
	}
	double ave = sum/n;
	double ans =0;
    //cout<<ave<<"\n";

    double total[n];
    for (int i=0;i<n;i++ )
    {
    	total[i] = ave - a[i];
    }

    for (int i=0;i<n;i++ )
    {
        int temp;
    	temp = total[i]*100;
    	//cout<<temp<<"\t";
    	double temp1 = temp;
    	total[i] = temp1/100.00;
    }
    /*cout<<"\n";
    for (int i=0;i<n;i++ )
    {
    	cout<<total[i]<<"\t";
    }
*/

	for (int i=0;i<n;i++ )
	{
		if(total[i] > 0)
            ans += total[i];
	}
	cout<<ans;




}
