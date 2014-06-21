#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<functional>
#include<set>
#include<list>

using namespace std;

int main()
{
    int no_of_oper;
    int med=0;
    cin>>no_of_oper;
    int element;
    vector<int> array;
    vector<int>::iterator itr;

    for(int operation=0;operation < no_of_oper;++operation)
    {
        char r_or_a;
        cin>>r_or_a;
        cin>>element;

        if(r_or_a=='r')
        {
            if((itr = find(array.begin(),array.end(),element)) != array.end())
            {
                array.erase(itr);
            }
            else
            {
                cout<<"Wrong!\n";
                continue;
            }
        }
        else if(r_or_a=='a')
        {
            array.push_back(element);
        }

        //Finding Median
        if(array.empty())
        {
            cout<<"Wrong!\n";
            continue;
        }
        else
        {
            nth_element(array.begin(),array.begin() + (array.size()-1)/2,array.end());

            if(array.size()%2==1)
            {
                cout<<array[(array.size()-1)/2]<<"\n";
            }
            else
            {
                nth_element(array.begin(),array.begin() + (array.size()-1)/2 + 1,array.end());

                cout<<(array[(array.size()-1)/2] + array[(array.size()-1)/2 + 1])/2.0<<"\n";
            }
        }
    }

}

