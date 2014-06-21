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

double min(double a,double b, double c)
{
    if(a<b)
    {
        if(a<c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if(b<c)
        {
            return b;
        }
        else
        {
            return c;
        }
    }
}

class FoxPaintingBalls
{
public:
    long long theMax(long long r,long long g, long long b,int n)
    {
        int balls = 0;
        int e =33;
        double r_mul=r,g_mul=g,b_mul=b;
        balls = n*(n+1)/2;
        int variable = balls%3;

        int min_each=0;

        if(balls>=3)
        {
            min_each = ceil(balls/3);
        }
        else if(balls = 1)
        {
            return (r+g+b);
        }
        else if(balls<3)
        {
            return (min(r_mul,g_mul,b_mul))*3;
        }
        if(r<min_each||g<min_each||b<min_each)
        {
            return 0;
        }
        if(min_each!=0)
        {
            r_mul = r/min_each;
            g_mul = g/min_each;
            b_mul = b/min_each;
        }
        double total_min =0;
        total_min = floor(min(r_mul,g_mul,b_mul));

        for(int i = total_min;i>0;i--)
        {
            if(abs((r+g+b) - total_min*9)<total_min*variable)
            {
                total_min--;
            }
            else
            {
                break;
            }

        }

        return total_min;
    }
};

int main()
{
    FoxPaintingBalls a;
    cout<<a.theMax(2,2,2,3);
}



