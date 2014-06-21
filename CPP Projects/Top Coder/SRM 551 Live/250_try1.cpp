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


class ColorfulBricks
{
    public:
    int countLayouts(string mem)
    {
        char color1 = 'a';
        char color2 = 'a';

        color1 = mem[0];

        for (int i=0;i<mem.size();i++ )
        {
        	if(mem[i] != color1)
        	{
        	    color2 = mem[i];
        	    break;
        	}
        }
        for (int i=0;i<mem.size();i++ )
        {
        	if((mem[i] != color1) && (mem[i] != color2))
        	{
        	    return 0;
        	}
        }
        if(color2 =='a')
        {
            return 1;
        }
        return 2;
    }
};

int main()
{
    ColorfulBricks a;
    cout<<a.countLayouts("AABC");
}


