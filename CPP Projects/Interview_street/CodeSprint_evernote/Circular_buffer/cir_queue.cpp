#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string buffer[n];

    int cur = -1;
    int last = -1;
    int total_ele=0;
    int total_insertion=0;
    int counter;

    while(1)
    {
        char choice;
        cin>>choice;

        int no_ele;
        string temp;

        if(total_ele==0)
        {
            cur=-1;
            last=-1;
            total_insertion=0;
        }


        switch(choice)
        {
        case 'A':
            cin>>no_ele;
            for(int i=0; i<no_ele; i++)
            {
                cin>>temp;
                cur = (cur+1)%(n);
                buffer[cur]=temp;
                if(total_ele==0)
                {
                    last = (last+1)%n;
                }

                if(total_ele<n)
                {
                    total_ele++;
                }

                total_insertion++;


                if(total_insertion>n && cur==last)
                {
                    last = (last+1)%n;
                }
            }
            break;

        case 'R':
            cin>>no_ele;
            for(int i=0; i<no_ele; i++)
            {
                last = (last+1)%(n);
                total_ele--;
                total_insertion--;

            }
            break;

        case 'L':
            counter = last;
            for (int i=0;i<total_ele;i++ )
            {
            	cout<<buffer[counter]<<"\n";
            	counter = (counter+1)%(n);
            }
            break;

        case 'Q':
            exit(0);

        default :
            continue;

        }
    }


}
