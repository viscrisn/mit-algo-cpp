#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int test;
    cin>>test;

    char temp[5];
    int a[test][test];

    for(int i=0;i<test;i++)
    {
        for(int j = 0;j<test;j++)
        {
            cin>>temp;
            if(temp[0]=='N')
            {
                a[i][j] = 0;
            }
            else
            {
                a[i][j] = 1;
            }
        }
    }

    int ans[test];

    for(int i=0;i<test;i++)
    {
        ans[i]= a[i][i];
    }


    for(int i=0;i<test;i++)
    {
        int flag = 0;
        for(int j = 0;j<test;j++)
        {
            if(ans[j]!=a[i][j])
            {
                flag = 1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
        }
    }



}
