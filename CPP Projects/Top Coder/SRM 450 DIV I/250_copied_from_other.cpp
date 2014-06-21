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

#define MAX 1024
using namespace std;

class StrangeComputer
{
    public:
    int setMemory(string mem)
    {
        int ans=0,f='0';
        for (int i=0;i<mem.size();i++ )
        {
        	if(mem[i] != f)
        	{
        	    ans++;
        	    f=mem[i];
        	}
        }
        return ans;
    }
};

int main()
{
    StrangeComputer a;
    cout<<a.setMemory("111000111");
}
