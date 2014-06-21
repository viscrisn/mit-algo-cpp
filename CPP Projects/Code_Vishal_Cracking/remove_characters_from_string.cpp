#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

char *rem_chars(char *char_buf,char *rem_buf)
{
    bool hash_array[256];
    memset(hash_array,false,sizeof(bool)*256);
    for (int i=0;i<strlen(rem_buf);i++ )
    {
    	hash_array[rem_buf[i]] = true;
    }
    int len = strlen(char_buf);
    int current=0, source=0;
    while(source<len)
    {
    	if(hash_array[char_buf[source]]==false)
            char_buf[current++] = char_buf[source];
        source++;
    }
    char_buf[current] = '\0';
    return char_buf;
}

int main()
{
    char buf[1000], rem[256];
    cout<<"Enter main string: ";
    cin.getline(buf,1000,'\n');
    cout<<"Enter remove character array: ";
    cin>>rem;
    cout<<rem_chars(buf,rem);

}
