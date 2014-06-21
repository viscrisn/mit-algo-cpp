#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int cases=n;
    int result[n+1];
    int k=0;


    while(n>0)
    {

    int a;
    float flag=0;
    cin>>a;

    float b=sqrt(a);
    int c=sqrt(a);

    for(int j=c;j>=0;j--)
    {
        for(int i=0;i<=c;i++)
        {
            int isq=i*i;
            int jsq=j*j;

            int ijsq=isq+jsq;
            if(ijsq==a)
            {
                if(isq==jsq)
                {
                    flag++;
                }
                //cout<<"\n+1 at"<<j<<" "<<i<<"\n";
                flag++;
                break;
            }
            if(ijsq>a)
            {
                break;
            }
        }
    }
    int intflag=flag;
    if(flag/2==intflag/2)
        result[k]=flag/2;
    else
        result[k]=intflag/2+1;

        k++;
        n--;
    }
    for(int i=0;i<cases;i++)
        cout<<"Case #"<<i+1<<": "<<result[i]<<"\n";

}
