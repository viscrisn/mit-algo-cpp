#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

//Time Complexity: O(n)

bool nxt_permute(char* s)
{
    if(s==NULL)
        return false;

    int len = strlen(s);
    int cur=-1;
    //Finding the position for swap
    for (int i=len;i>0;i-- )
    {
    	if(s[i] > s[i - 1])
    	{
    	    cur =i-1;
    	    break;
    	}
    }

    if(cur==-1)
        return false;

    int swp=cur+1;
    //finding the number to swap
    for (int i=swp;i<len;i++ )
    {
    	if((s[cur] < s[i])&&(s[i] < s[swp]))
        {
            swp = i;
        }
    }
    swap(s[cur],s[swp]);

    //if string is very large, we can use counting sort to get O(n) (in this case).
    sort(s+cur+1,s+len);

    return true;

}
int main()
{
    char s[20] = "1286574";
    if(nxt_permute(s))
    {
        cout<<"Next permutation is:\t"<<s;
    }
    else
    {
        cout<<"Not possible\n";
    }
}
