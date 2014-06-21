#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>

using namespace std;

int stringOccurrences(int n, char* str)
{
	n++;
	string in = str;
	string P[n];
    P[0] = "X";P[1] = "Y";P[2] = "Z";
    for (int i=3;i<n;i++ )
    {
    	P[i].assign(P[i-2]);
    	P[i].append(P[i-3]);
    }
    /*
    for (int i=0;i<n;i++ )
    {
    	cout<<P[i]<<"\n";
    }
    */
    int in_len = in.length();
    /*
    string in_r = "";
    in_r.assign(in);
    for (int i=0;i<in_len;i++ )
    {
    	in_r.at(i) = 'W';
    }
    */
    int idx = n-1;
    int count =0;
    int ii = P[idx].find(in);
    while(ii != -1 )
    {
        count++;
        //P[idx].replace(ii,in_len,in_r);
        //P[idx].erase(ii,in_len);
        cout<<P[idx]<<"\t";
        ii = P[idx].find(in,ii+1);
    }
    return count;
}

bool validation(int n, char* s)
{
    if(n>40 || n<=2)
        return false;

    int len = strlen(s);
    for (int i=0;i<len;i++ )
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
