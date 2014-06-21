#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <map>
#include <fstream>

using namespace std;

char non_rep_array(char *char_buf)
{
    int len = strlen(char_buf);
    int array[256];
    memset(array,-1,sizeof(int)*256);
    char temp;
    for (int i=0;i<len;i++ )
    {
        temp = char_buf[i];
        if(array[temp] == -1)
            array[temp] = i;
        else
            array[temp] = len;
    }
    int index = len;
    for (int i=0;i<256;i++ )
    {
    	if(array[i] < index && array[i]!=-1)
            index = array[i];
    }
    if(index == len)
        return NULL;
    else
        return char_buf[index];
}

char non_rep_hash(char *char_buf)
{
    int len = strlen(char_buf);
    map<char, bool> hash_table;
    map<char, bool>::iterator ii;
    char temp;
    for(int i =0;i<len;i++)
    {
        temp = char_buf[i];
        ii = hash_table.find(temp);
        if(ii == hash_table.end())
            hash_table.insert(pair<char,bool>(temp,true));
        else
            (*ii).second = false;
    }
    for (int i=0;i<len;i++ )
    {
    	temp = char_buf[i];
    	ii = hash_table.find(temp);
    	if((*ii).second == true)
            return temp;
    }
    return NULL;
}

int main()
{
    char buf[1000];
    cin.getline(buf,1000,'\n');
    cout<<"First non-repeating character is: ";
    //cout<<non_rep_hash(buf);
    cout<<(char)non_rep_array(buf);


    return 0;
}
