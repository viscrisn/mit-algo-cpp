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

using namespace std;

int main()
{
	string s("");
	cin>>s;
	int len = s.length();
	char alpha[26];
	cin>>alpha;
	int bad;
	cin>>bad;

    set<string> ss;
    set<string>::iterator ii;

    string temp("");

    int total_good = 0;

    for (int i=0;i<26;i++ )
    {
    	if(alpha[i]=='1')
    	{
    	    total_good++;
    	}
    }


    for (int i=1;i<=len;i++ )
    {
    	for (int j=0;j<len;j++ )
    	{
    	    if(total_good==0)
    	    {
    	        if(i>bad)
    	        {
    	            i = len;
    	            break;
    	        }
    	    }
    	    int bad_s = 0;
    		temp.assign(s,j,i);
    		for (int k=0;k<=i;k++ )
    		{
    			if(alpha[temp[k]-97]=='0')
    			{
    			    bad_s++;
    			    if(bad_s>bad)
    			    {
    			        break;
    			    }
    			}
    		}
    		if(bad_s<=bad)
                ss.insert(temp);
    	}
    }
    for (ii=ss.begin();ii!=ss.end();ii++ )
    {
    	cout<<*ii<<"\t";
    }
    cout<<ss.size();

}
