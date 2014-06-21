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
#include<fstream>

using namespace std;

bool is_anagram(char *str1,char *str2);

int main()
{
    char buf1[100],buf2[100];
    char *str1 = buf1,*str2 = buf2;
	cin>>str1>>str2;

	if(is_anagram(str1,str2))
        cout<<"Yes, it is an anagram\n";
    else
        cout<<"No, its not an anagram\n";
}
bool is_anagram(char *str1,char *str2)
{
    if(str1 == NULL || str2 == NULL)
        return false;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if(len1!=len2)
        return false;
    int count_array[256] = {};
    for(int i=0;i<len1;i++)
    {
        count_array[str1[i]]++;
        count_array[str2[i]]--;
    }
    for (int i=0;i<256;i++ )
    {
    	if(count_array[i]!=0)
            return false;
    }
    return true;
}
