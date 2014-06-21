#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class to_lower
{
    public:
        char operator() (char c) const
        {
            return tolower(c);
        }
};

string lower(const string &str)
{
    string lcase = str;
    transform(str.begin(),str.end(),lcase.begin(),to_lower());

    return lcase;
}
int main()
{
	string str = "ViShAl KrIsHnA";
	cout<<str;
    cout<<"\n";
	str = lower(str);
	cout<<str;

}
