#include<iostream>

using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test)
    {
        test--;

        int buildings;
        cin>>buildings;

        char bombs[buildings];
        for (int i=0;i<buildings;i++ )
        {
        	cin>>bombs[i];
        }

        for(int i=0;i<buildings;i++)
        {
            if(bombs[i]=='1')
            {
                if((i-1)>=0)
                {
                    if(bombs[i-1]!='1')
                    {
                        bombs[i-1]='2';
                    }
                }

                if((i+1)<=buildings)
                {
                    if(bombs[i+1]!='1')
                    {
                        bombs[i+1]='2';
                    }
                }
            }
        }
        int count=0;
        for(int i=0;i<buildings;i++)
        {
            if(bombs[i]=='0')
            {
                count++;
            }
        }
        cout<<count<<endl;

    }
}

