#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int m,n,t;
    scanf("%d",&t);
    while(t--)
    {
//cin>>n>>m;
        scanf("%d",&n);
        scanf("%d",&m);
        int l[n],a[m],b[m],c[m],d[m],cnt=0;
        for(int i=0; i<n; i++)
            cin>>l[i];
        for(int i=0; i<m; i++)
        {
            int j=n-1;
            cin>>a[i]>>b[i]>>c[i];
            d[i]=(a[i]*a[i]+b[i]*b[i]+c[i]*c[i]);
            while(j>=0)
            {
//if(l[j]>0)
//{
                if(l[j]<=a[i]||l[j]<=b[i]||l[j]<=c[i]||(l[j]*l[j])<=d[i])
                {
                    cnt++;
                    int k=j;
                    while(k+1<n)
                    {
                        l[k]=l[k+1];
                        k++;
                    }
                    n--;
                    j--;
//l[j]=-1;
                }
                else j--;

//}

//j--;
            }
        }
        printf("%d\n",cnt);
    }
}
