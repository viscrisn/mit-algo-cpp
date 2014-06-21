#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

int bin_to_dec(char *str)
{
    uint32_t len = strlen(str);
    stack<int> stk;
    for (int i=0;i<len;i++ )
    {
    	stk.push(str[i] - '0');
    }
    int decimal = 0;
    int power = 1;
    while(stk.empty()!=true)
    {
        decimal += stk.top() * power;
        power *= 2;
        stk.pop();
    }
    return decimal;
}

int main()
{
	char buf[33];
	cin>>buf;
	cout<<bin_to_dec(buf);
}
