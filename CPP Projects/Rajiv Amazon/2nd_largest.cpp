#include<iostream>

//Time Complexity: O(n)

using namespace std;

int sec_larg(int a[],int n)
{
    //Assuming n>=2, else include if(n<2) "not possible"
    int lar,lar2;
    if(a[0]>a[1])
    {
        lar = a[0];
        lar2 = a[1];
    }
    else
    {
        lar = a[1];
        lar2 = a[0];
    }

    for (int i=2;i<n;i++ )
    {
    	if(a[i]>lar)
    	{
    	    lar2 = lar;
    	    lar = a[i];
    	}
    }
    return lar2;
}
int main()
{
    int n;
    cout<<"Enter number of elements\n";
    cin>>n;
	int a[n];
	cout<<"Enter the elements\n";
	for (int i=0;i<n;i++ )
	{
		cin>>a[i];
	}
	cout<<"Second largest no is:\t"<<sec_larg(a,n);

}
