#include<iostream>

using namespace std;

int main()
{
    int menu[12];

    int two=1;
    for(int i=0;i<12;i++)
    {
        menu[i] = two<<i;
    }

    int test =0;
    cin>>test;
    int test_1=test;
    int ans[test];
    int cases=0;
    while(test)
    {
        int number =0;
        cin>>number;
        int count = 0;

        while(number!=0)
        {
            int sub=0;
            for(int i=0;i<12;i++)
            {
                if(number<menu[i])
                {
                    break;
                }
                else
                {
                    sub = menu[i];
                }
            }
            number = number - sub;
            count++;
        }

        ans[cases] = count;


        test--;
        cases++;
    }
    for(int i=0;i<test_1;i++)
    {
        cout<<ans[i]<<"\n";
    }
}
