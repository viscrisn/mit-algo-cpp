/*the question is simple
we have 1...9 telefon numbers,and we input some numbers such as 12386930 and we are to output the unmatched numbers 4 ,5 ,7
*/

#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int tele[] = {0,1,2,3,4,5,6,7,8,9};
	int c='0';
	bool found[10] = {false};
	while((c=getchar())!='\n')
	{
	    c = c - '0';
	    found[c] = true;
	}
	cout<<"The unmatched numbers are\n";
	for (int i=0;i<10;i++ )
	{
		if(found[i]==false)
        {
            cout<<tele[i]<<" ";
        }
	}
	cout<<"\n";
	return 0;
}
