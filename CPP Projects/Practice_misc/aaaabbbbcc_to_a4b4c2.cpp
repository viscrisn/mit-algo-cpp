#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int test;
    cin>>test;

    while(test)
    {
        test--;
        char a[1000];
        cin>>a;

        int len = strlen(a);
        int index = 0;
        a[index++] = a[0];
        int count =1;

        for (int i=1; i<len+1; i++ )
        {
            if(a[i]==a[i-1])
            {
                count++;
                continue;
            }
            else
            {
                if(count>1)
                    a[index++] =count+'0';

                a[index++] =a[i];
                count = 1;
            }

        }
        a[index]='\0';
        cout<<a<<"\n";
    }
}
