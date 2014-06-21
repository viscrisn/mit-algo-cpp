
//Name1:						Name2:
//Del1:							Del2:
//Team ID:
//The Program aims to find the length of the longest array of prime numbers in a given array
//INPUT - the first line takes an integer n. the next n lines take elements of the array.
//OUTPUT - Outputs the length of longest array of prime numbers.
//SAMPLE INPUT- 6
//				1 2 3 12 4 7
//Sample OUTPUT- 2

#include <iostream>
//#include <iostream.h>
using namespace std;

int c(int n)
{
    //or n==1
    if((n==0)||(n==1))
        return 0;
    int flag=1;

    //n<=n/2

    for(int i=2; i<=n/2; i++)
    //if(n%i!=0)
        if(n%i==0)
            flag=0;
    return flag;
}
int main()
{
    int* p;
    int n;
    cin>>n;
    p=new int[n];
    for(int i=0; i<n; i++)
        cin>>p[i];
    int t[n];
    int j=0,i;
    //semicolon removed
    for(i=0; i<n; i++)
        t[i]=0;

    //for(int i=0; i<n; i--)
    for(int i=0; i<n; i++)
    {
        //if(!c(p[i]))
        if(c(p[i]))
            //t[j]=1;
            t[j]+=1;
        else
            //j--;
            j++;
    }

    int max=t[0];

    for(int i=0; i<n; i++)
        //if(t[i]<max)
        if(t[i]>max)
            max=t[i];
    cout<<max;
}
