#include<iostream>
#include "InsertRemove.h"
#include "Median.h"

using namespace std;

int num_array[100000];

int main()
{
    int status;
    int no_of_oper;
    cin>>no_of_oper;
    int no_of_ele=0;
    int element;

    while(no_of_oper!=0)
    {
        no_of_oper--;
        char r_or_a;
        cin>>r_or_a;
        cin>>element;

        if(r_or_a=='r')
        {
            status = Remove(num_array,no_of_ele,element);
            if(status==-1)
            {
                cout<<"Wrong!\n";
                continue;
            }
        }
        else if(r_or_a=='a')
        {
            Insert(num_array,no_of_ele,element);
        }

        //Finding Median
        if(no_of_ele==0)
        {
            cout<<"Wrong!\n";
            continue;
        }
        else
        {
            cout<<Median(num_array,no_of_ele)<<"\n";
        }
    }

}

