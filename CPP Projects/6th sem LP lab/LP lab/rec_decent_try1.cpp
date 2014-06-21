/*
S -> TL
T -> int|float
L -> L,id | id

S -> TL
T -> int|float
L -> idL'
L' -> ,idL' | e

Sample Input (Space after every character)
int a , b , c ;
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

void S();
void T();
void Ldash();
void L();
void getnexttoken();
void match();

char a[100], token[100];
int m =1,len = 0,count = 0;

void getnexttoken()
{
    if(m==1)
    {
        int  i = 0;
        while(a[len]== ' ' && len < strlen(a))
        {
            len++;
        }
        while(a[len]!= ' ' && len < strlen(a))
        {
            token[i++] = a[len++];
        }
        if(i>0)
            token[i] = '\0';
        cout<<token<<"\n";
        m==0;
    }
}
void match()
{
    m = 1;
}

void S()
{
    T();
    L();
    //getnexttoken();
    if(strcmp(token,";")==0)
    {
        match();
    }
    else
    {
        cout<<"Error in S\n";
        exit(0);
    }
}

void T()
{
    getnexttoken();
    if(strcmp(token,"int")==0||strcmp(token,"float")==0)
    {
        match();
    }
    else
    {
        cout<<"Error in T\n";
        exit(0);
    }
}

void L()
{
    getnexttoken();
    if(token[0]>='a'&&token[0]<='z')
    {
        match();
        Ldash();
    }
    else
    {
        cout<<"Error in L\n";
        exit(0);
    }
}

void Ldash()
{
    getnexttoken();
    if(strcmp(token,",")==0)
    {
        match();
        getnexttoken();
        if(token[0]>='a'&&token[0]<='z')
        {
            match();
            Ldash();
        }
        else
        {
            cout<<"Error in Ldash\n";
            exit(0);
        }
    }
}

int main()
{
    cout<<"Enter string to be parsed\n";
    cin.getline(a,100,'\n');
    S();
    cout<<"Success\n";
    return 1;
}
