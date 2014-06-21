/*Two strings are given. One of them is the initial string and other string contains characters as per their priority. Sort the initial string as per the given second string. characters in initial string may or may not be present in the second string. If not present, sort them in lexicographical order at the end of output.
eg. String1 – ddloyc, String2 – odl
Output – oddlcy*/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int hash_array[256] = {};

void create_hasharray(char str2[])
{
    int count = 1;
    int len = strlen(str2);
    for (int i=0;i<len;i++ )
    {
        hash_array[str2[i]] = count++;
    }
    for (int i=0;i<256;i++ )
    {
    	if(hash_array[i]==0)
            hash_array[i] = count++;
    }
}

bool hash_compare(char a, char b)
{
    if(hash_array[a] < hash_array[b])
        return true;
    return false;
}

int main()
{
	char str1[1000],str2[30];
	cin>>str1>>str2;
	int len = strlen(str1);
	create_hasharray(str2);
	sort(str1,str1+len,hash_compare);
	cout<<str1;
	//take care of boundary cases and modify accordingly
}
