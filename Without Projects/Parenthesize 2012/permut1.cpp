#include<iostream>

using namespace std;

int sort(int [],int);
void swap(int [],int, int);
void decrement(int[],int);
void fike(int[],int[],int);
int fact(int);

int main()
{
    long n1;
    int no_arr[20];
    cin>>n1;
    int count1=0;
    int flag1=0;
    int a[32],n;

    while(n1)
    {
        no_arr[count1]=n%10;
        if(no_arr[count1]==0)
        {
            count1--;
            flag1++;
        }
        n1=n1/10;
        count1++;
    }
    for(int i=0;i<count1;i++)
    {
        a[i]=no_arr[i];
    }



    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    sort(a,n);
    int c[n];

    int k;
    k=fact(n);
    int count=0;

    for(int i=0;i<k;i++)
    {
        count++;

//        lex(a,n);

        cout<<count<<" th permutation is: "<<"\t";
        for(int i=0;i<n;i++)
        {
           cout<<a[i]<<" ";
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


void lex(int b[],int n)
{


}

int largest(int a[],int n)
{
    int temp=a[0];
    for(int i=i;i<n;i++)
    {
        if(temp>a[i])
            swap(a,i-1,i)
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


