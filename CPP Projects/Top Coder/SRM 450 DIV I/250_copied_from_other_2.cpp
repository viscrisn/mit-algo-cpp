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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define S size()
class StrangeComputer
{
    public:
    int setMemory(string mem)
    {
        int ans=0,f='0';
        F(i,mem.S)
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

