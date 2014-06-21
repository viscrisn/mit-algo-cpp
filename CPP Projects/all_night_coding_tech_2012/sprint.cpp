#include<iostream>

using namespace std;

int main()
{
	int n;

	int a[1000];
	for (int i=0;i<1000;i++ )
	{
		a[i]=0;
	}
	float b[1000];
	for (int i=0;i<1000;i++ )
	{
		b[i]=0;
	}

    int c1=0,d1=0,e1=0,f1=0,g1=0;
    float a2=0,b2=0,c2=0,d2=0,e2=0,g2=0;

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    float ans=0;



    cout<<ans/n;

    cout<<"\n";

}
