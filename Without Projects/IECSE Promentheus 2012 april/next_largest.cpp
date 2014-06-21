#include<iostream>
#include<cstring>
#include<stdio.h>

using namespace std;
int main()
{

    int final[50];

    int cases;
    cin>>cases;

    int n=cases;
    int test=0;
    int count=0;

    while(cases)
    {
        count=0;
        cases--;

#include <algorithm>
#include <iostream>

void insert_a_zero(std::string & number)
{
    size_t nzeros = number.find_first_not_of('0');
    number = number.substr(nzeros);
    number.insert(1, nzeros + 1, '0');
}


int main()
{
    std::string number;
    while (std::cin >> number)
    {
        if (!next_permutation(number.begin(), number.end()))
        {
            insert_a_zero(number);
        }
        std::cout << number << '\n';
    }
    return 0;
}

template<typename Iter>
bool next_permutation(Iter first, Iter last)
{
    if (first == last)
        return false;
    Iter i = first;
    ++i;
    if (i == last)
        return false;
    i = last;
    --i;

    for(;;)
    {
        Iter ii = i;
        --i;
        if (*i < *ii)
        {
            Iter j = last;
            while (!(*i < *--j))
            {}
            iter_swap(i, j);
            reverse(ii, last);
            return true;
        }
        if (i == first)
        {
            \reverse(first, last);
            return false;
        }
    }
}









    final[test++]=count;
}

for(int test1=0;test1<n;test1++)
{
    cout<<final[test1]<<endl;
}

}
