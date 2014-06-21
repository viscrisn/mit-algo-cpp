//This program works fine.
//Fike's ordering. Challenge Completed.
//Challenge Given on 6/12/2011 by Rahul Anand at 12:14am.
//Challenge Completed on 6/12/2011 by Vishal Krishna at 7:12pm.

#include<iostream>

using namespace std;

int sort(int [],int);
void swap(int [],int, int);
void decrement(int[],int);
void fike(int[],int[],int);
int fact(int);

int main()
{
    int a[32],n;
    cout<<"Enter no of Marks";
    cin>>n;
    cout<<"Enter the Marks";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,n);
    int d[n],c[n];

    for(int i=0;i<n;i++)
    {
        d[i]=i;
    }
    int k;
    k=fact(n);
    int count=0;

    for(int i=0;i<k;i++)
    {
        count++;
        for(int i=0;i<n;i++)
        {
            c[i]=a[i];
        }
        fike(c,d,n);
        decrement(d,n-1);

        if(d[0]==-1)
            break;
        cout<<count<<" th permutation is: "<<"\t";
        for(int i=0;i<n;i++)
        {
           cout<<c[i]<<" ";
        }
        cout<<endl;
    }
}

int fact(int n)
{
    int k=1;
    for(int i=1;i<=n;i++)
    {
        k*=i;
    }
    return k;
}

void decrement(int d[],int n)
{
    if(d[0]==-1)
        return;
    if(d[n]==0)
    {
        d[n]=n+1;
        decrement(d,n-1);
    }
    d[n]--;

}

void fike(int b[],int d[],int n)
{
    int c[n];

    for(int i=0;i<n;i++)
    {
        c[i]=d[i];
    }

    for(int i=0;i<n;i++)
    {
        c[i]++;
    }

    for(int i=1;i<n;i++)
    {
        swap(b,i,c[i]-1);
    }


}

void swap(int t[],int i,int j)
{
    int temp;
    temp = t[i];
    t[i] = t[j];
    t[j] = temp;
}

int sort(int b[],int n)
{
    int temp;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(b[i]<b[j])
            {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }

}
















