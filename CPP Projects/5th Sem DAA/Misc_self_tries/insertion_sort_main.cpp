#include "Insertion_sort.h"

using namespace std;

int main()
{
    int len;
    cout<<"Enter no of elements\n";
    cin>>len;
    int a[len];
    cout<<"Enter the elements\n";
    for (int i=0;i<len;i++ )
    {
    	cin>>a[i];
    }

    i_sort(a,len);

    for (int i=0;i<len;i++ )
    {
    	cout<<a[i]<<"\t";
    }

}
