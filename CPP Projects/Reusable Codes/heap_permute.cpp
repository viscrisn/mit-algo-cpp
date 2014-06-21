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

char a[100];
int len;


//Generates the permutation of a string
//generates by MSB
//reversing makes it generate in LSB
//i.e. lex order
void heap_permute(int n)
{
    if(n == 1)
    {
        //reverse(a,a+len);//added to print in lex order
        cout<<a<<"\n";
        //reverse(a,a+len);//for lex order
    }
    else
        for (int i=0;i<n;i++ )
        {
        	heap_permute(n-1);
        	if(n%2==1)
                swap(a[0],a[n-1]);
            else
                swap(a[i],a[n-1]);
        }
}
int main()
{
	cin>>a;
	len = strlen(a);
	//reverse(a,a+len);//for lex order
	heap_permute(len);
}
