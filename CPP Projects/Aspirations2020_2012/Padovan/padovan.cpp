//# include "padovanstring.h"
#include<string.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

char * P(int n)
{
    char * temp = (char *) malloc(n * sizeof(char));
    if(n==0)
    {
        return "X";
    }
    else if(n==1)
    {
        return "Y";
    }
    else if(n==2)
    {
        return "Z";
    }

    temp = strcat(P(n-3),P(n-2));
    return temp;
}

int stringOccurrences(int n, char* str)
{
    if(n>40)
        return -1;

    cout<<P(6);
	return 0;
}

int main()
{
    stringOccurrences(6,"asd");
}
