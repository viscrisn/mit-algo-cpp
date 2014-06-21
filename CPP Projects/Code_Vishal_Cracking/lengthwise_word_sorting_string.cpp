#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

bool comp_func(char *a, char *b)
{
    return strlen(a) < strlen(b);
}

int main()
{
    char char_buf[1000];
    cin.getline(char_buf,1000,'\n');
    int num_words = 1;
    int len = strlen(char_buf);
    for (int i=0;i<len;i++ )
    {
    	if(char_buf[i]==' ')
            num_words++;
    }
    char *dict[num_words];
    dict[0] = (char*)(malloc(sizeof(char)));
    dict[0] = strtok(char_buf," ,.");

    for (int i=1;i<num_words;i++ )
    {
    	dict[i] = (char*)(malloc(sizeof(char)));
        dict[i] = strtok(NULL," ,.");
    }
    sort(dict,dict+num_words,comp_func);
    for (int i=0;i<num_words;i++ )
    {
    	cout<<dict[i]<<" ";
    }
}
