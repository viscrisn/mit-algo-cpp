#include<iostream>

using namespace std;

void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int count=0;

void permute(char *a, int i, int n)
{
    int j;
    int fl=0;
    if (i == n)
    {

        for (int i=0; i<n; i++ )
        {
            if(a[i-1]==a[i])
            {
                fl=1;
                break;
            }
        }
        if(fl!=1)
        {
            count++;
            //cout<<a<<"\n";
        }
    }
    else
    {
        for (j = i; j <= n; j++)
        {
            swap((a+i), (a+j));
            permute(a, i+1, n);
            swap((a+i), (a+j));
        }
    }
}

int main()
{
    int test;
    cin>>test;
    while(test)
    {
        test--;
        int p=0,q=0,r=0,s=0;

        cin>>p>>q>>r>>s;

        int n = p+q+r+s;
        int k=0;

        char a[1000];
        for (int i=0; i<p; i++ )
        {
            a[k++] = 'P';
        }
        for (int i=0; i<q; i++ )
        {
            a[k++] = 'Q';
        }
        for (int i=0; i<r; i++ )
        {
            a[k++] = 'R';
        }
        for (int i=0; i<s; i++ )
        {
            a[k++] = 'S';
        }
        a[k] = '\0';

        permute(a, 0, n-1);

        if(p>1)
            count = count/p;
        if(q>1)
            count = count/q;
        if(r>1)
            count = count/r;
        if(s>1)
            count = count/s;

        cout<<count;
        cout<<"\n";
    }
}



