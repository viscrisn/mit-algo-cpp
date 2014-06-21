#include<iostream>

using namespace std;

//Working
int main()
{
    int n,k,temp1,temp2;
    cin>>n>>k;
    int ans=0;
    for (int i=0;i<k;i++)
    {
        cin>>temp1;
        if(temp1>0) ans++;
    }
    if(temp1==0) temp1 = 101;
    for (int i=k;i<n;i++)
    {
    	cin>>temp2;
    	if(temp2 >= temp1) ans++;
    }
    cout<<ans;
}
