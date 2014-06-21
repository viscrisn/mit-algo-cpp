//Attempt started 5:58pm 02-08-2012
//Code Completion at 6:12pm 02-08-2012
//Successfull debugging and submission at 6:20pm
//Execution time : 0.24secs, 2.4M of memory.
//Worked nicely in first try

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
