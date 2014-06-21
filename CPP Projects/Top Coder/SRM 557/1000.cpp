#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<sstream>
#include<queue>
#include<cstdlib>
#include<map>
#include<set>

using namespace std;


class FoxAndMountain
{
public:
    int count(int n, string history)
    {
        int len = history.length();
        long long ans =0;
        if(n%2==1)
        {
            return 0;
        }
        int final_height = 0;
        int m_height = n - len;
        for (int i=0; i<len; i++ )
        {
            if(history[i]=='U')
            {
                final_height++;
            }
            else
            {
                final_height--;
            }
        }
        if(m_height < final_height)
        {
            return 0;
        }
        if(len == n)
        {
            if(final_height == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        int temp = m_height - abs(final_height);
        //temp /= 2;
        ans = 1;
        for (int i=0;i<temp;i++ )
        {
        	ans *= 2;
        }
        return (ans%1000000009);
    }
};

int main()
{
    FoxAndMountain a;

    cout<<a.count(50,"U");
}





