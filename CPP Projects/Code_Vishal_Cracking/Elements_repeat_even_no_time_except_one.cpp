#include <iostream>

using namespace std;

int find_rep(int *arr,int n)
{
    for (int i=1;i<n;i++ )
    {
        arr[0] ^= arr[i];
    }
    return arr[0];
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++ )
    {
        cin>>arr[i];
    }
    cout<<"Number Repeated Odd no. of times:\n";
    cout<<find_rep(arr,n);
    return 0;

}
