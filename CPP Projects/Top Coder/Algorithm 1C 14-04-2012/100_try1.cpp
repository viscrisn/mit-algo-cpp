#include <iostream>
#include <cstdio>
#include<cstring>

using namespace std;

bool palin(char[],int);
int count_mistake(char[],int);


int main()
{
    int t;
    int alphabet[26];

    char c;
    char ch[50];
    int even=0;
    int count=0;
    int mistake=0;

    for (int x=0;x<26;x++)
    {
        alphabet[x]=0;
    }

    while((c=getchar())!=10)
    {
        ch[count++]=c;
        alphabet[c-97]++;
    }

    for (int i=0;i<26;i++)
    {
        if((alphabet[i]%2)!=0)
        {
            even++;
        }
    }

    if(even>=2)
    {
        cout<<-1;
        return 0;
    }

    if(palin(ch,count))
    {
        cout<<0;
        return 0;
    }
    mistake = count_mistake(ch,count);
    mistake/=2;

    //cout<<mistake<<endl;

    if(mistake==1)
    {
        cout<<1;
        return 0;
    }
    else
    {
        cout<<(mistake - 1);
        return 0;
    }





    /*for (int x=0;x<count;x++)
    {
        cout<<ch[x];
    }
    cout<<endl;
    palin(ch,count);
    */
}

bool palin(char str[],int x)
{

    x=x-1;
    for(int i = 0; i <= x; i++)
    {
        if (str[i] == str[x-i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int count_mistake(char str[],int x)
{
    int t=0;

    x=x-1;
    for(int i = 0; i <= x; i++)
    {
        if (str[i] == str[x-i])
        {
            continue;
        }
        else
        {
            t++;
        }
    }
    return t;
}


