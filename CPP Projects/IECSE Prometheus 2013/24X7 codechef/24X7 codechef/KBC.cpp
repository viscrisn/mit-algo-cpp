#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int testno = 0; testno < test ; testno++ )
    {

        int num_contestants =0;
        cin>>num_contestants;

        int ratings[num_contestants];

        for (int i=0; i<num_contestants; i++ )
        {
            cin>>ratings[i];
        }

        int gift_hamper[num_contestants];

        for (int i=0; i<num_contestants; i++ )
        {
            gift_hamper[i]=1;
        }

        for (int i=1; i<num_contestants; i++ )
        {
            if(ratings[i]>ratings[i-1])
            {
                gift_hamper[i]+=gift_hamper[i-1];
            }
        }

        for (int i=num_contestants; i>0; i-- )
        {
            if((ratings[i]<ratings[i-1])&&
                    (gift_hamper[i]>=gift_hamper[i-1]))
            {
                gift_hamper[i-1]+=gift_hamper[i] - gift_hamper[i-1] + 1;
            }
        }


        int total_gift_hamper=0;
        for (int i=0; i<num_contestants; i++ )
        {
            total_gift_hamper+=gift_hamper[i];
        }

        cout<<total_gift_hamper<<"\n";

    }
}

