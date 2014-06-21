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


class TypingDistance
{

public:
    int search(string keyboard, char s)
    {
        for (unsigned int i=0;i<keyboard.length();i++ )
        {
        	if(keyboard[i] == s)
        	{
        	    return i;
        	}
        }
        return -1;
    }
    int minDistance(string keyboard, string word)
    {
        int prev=0,cur=0;
        unsigned int i=0,sum=0;
        prev = search(keyboard,word[i++]);

        while(i<word.length())
        {
            cur = search(keyboard,word[i]);
            sum+= abs(cur - prev);
            prev = cur;
            i++;
        }
        return sum;
    }
};

int main()
{
    TypingDistance a;

    cout<<a.minDistance("qwertyuiop","potter")<<"\n";
    cout<<a.minDistance("tc","tctcttccctccccttc")<<"\n";
    cout<<a.minDistance("a","aaaaaaaaaaa")<<"\n";
    cout<<a.minDistance("kwadrutove","rowerowe")<<"\n";
}



