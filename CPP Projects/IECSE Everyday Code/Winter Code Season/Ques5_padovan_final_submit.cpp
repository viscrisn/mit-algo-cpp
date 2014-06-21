#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>

using namespace std;


//Time Complexity: O(length(P(n))Xlength(str))

//More efficient than normal brute force checking as string library is used,
//which is implemented more efficiently in terms of efficiency.

//The advantage of using sting functions (STL) over char* functions is,
//string functions were defined later, by people doing Ph.Ds etc. So it was made very efficient,
//By lowering it to machine level as much as possible,
//yet providing more functions to the user.
//Whereas char* functions were simply inbuilt functions during the time of language implementation.
//So, function prototype (int n, string str) would have been better in terms of efficiency.
//Thank you for reading this information.
//Was meant to while away some time. :P
//-Vishal Krishna

int stringOccurrences(int n, char* str)
{
    n++;
    string in = str;
    string P[n];
    P[0] = "X";
    P[1] = "Y";
    P[2] = "Z";
    for (int i=3; i<n; i++ )
    {
        P[i].assign(P[i-2]);
        P[i].append(P[i-3]);
    }

    int in_len = in.length();
    int idx = n-1,count =0;
    int ii = P[idx].find_first_of(in);

    while(ii != -1 )
    {
        count++;
        ii = P[idx].find_first_of(in,ii+in_len);
    }
    return count;
}

bool validation(int n, char* s)
{
    if(n>40 || n<=2)
        return false;

    int len = strlen(s);
    for (int i=0; i<len; i++ )
    {
        if(s[i]!= 'X' && s[i]!= 'Y' && s[i]!= 'Z')
            return false;
    }
    return true;

}
int main()
{
    int n;
    cout<<"int n = ";
    cin>>n;

    char str[45];
    cout<<"String str = ";
    cin>>str;

    if(validation(n,str))
        cout<<stringOccurrences(n,str);
    else
        cout<<-1;
}

