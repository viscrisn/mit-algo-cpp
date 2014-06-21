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
    cin>>no_of_oper;
    int element;
    multiset<int> array;
    multiset<int>::const_iterator itr;

    for(int operation=0;operation < no_of_oper;++operation)
    {
        char r_or_a;
        cin>>r_or_a;
        cin>>element;

        if(r_or_a=='r')
        {
            if((itr = array.find(element)) != array.end())
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
            array.insert(element);
        }

        //Finding Median
        if(array.empty())
        {
            cout<<"Wrong!\n";
            continue;
        }
        else
        {
            itr = array.begin();
            advance(itr, (int)(array.size()-1) / 2);

            if(array.size()%2==1)
            {
                cout<<*itr<<"\n";
            }
            else
            {
                cout<<(*itr + *(++itr))/2.0<<"\n";
            }
        }
    }

}
