#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<functional>
#include<stack>
#include<set>
#include<queue>
#include<fstream>

using namespace std;

int main()
{
    freopen("sq_digits_dq.txt","w",stdout);
    uint64_t arr[1000] = {0};
    int count = 0;
    uint64_t mul = 0;
    uint64_t temp = 0;
    for (uint64_t i=0; i<100001; i++ )
    {
        mul = i*i;
        temp = mul;
        bool flag = true;
        while(mul)
        {
            if(mul%10 != 0 && mul%10 != 1 && mul%10 != 4 && mul%10 != 9)
            {
                flag = false;
                break;
            }
            mul/=10;
        }
        if(flag == true)
            arr[count++] = temp;
    }
    for (int i=0; i<count; i++ )
    {
        cout<<arr[i]<<"ULL,";
    }
    cout<<count;


}
