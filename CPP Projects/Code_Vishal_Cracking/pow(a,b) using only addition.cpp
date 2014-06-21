#include <iostream>

using namespace std;



/*
//Time Complexity - O(n)
uint64_t mul(uint64_t num1,uint64_t num2)
{
    uint64_t temp = 0;
    for (uint64_t i=0;i<num2;i++ )
    {
    	temp += num1;
    }
    return temp;
}

// Time Complexity - O(b)
uint64_t pow(uint64_t a, uint64_t b)
{
    uint64_t ans = 1;
    for(uint64_t i =0;i<b;i++)
    {
        ans = mul(ans,a);
    }
    return ans;
}
*/

/*
//Time complexity - O(log(num2))
uint64_t mul(uint64_t num1, uint64_t num2)
{
    if(num2 == 1)   return num1;
    uint64_t temp_var = mul(num1,num2/2);
    if(num2%2==0)
        return temp_var + temp_var;
    else
        return temp_var + temp_var + num1;
}
//Time Complexity - O(logb)
uint64_t pow(uint64_t a, uint64_t b)
{
    if(b == 1)  return a;
    uint64_t temp_var = pow(a,b/2);
    if(b%2==0)
        return mul(temp_var,temp_var);
    else if(b%2==1)
        return  mul(mul(temp_var,temp_var),a);
}
*/

int main()
{
    uint64_t a,b;
    cin>>a>>b;
    cout<<(pow(a,b));
}
