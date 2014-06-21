#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>

using namespace std;

int main()
{
	int test_total;
	cin>>test_total;

	for (int test_no=0;test_no<test_total;test_no++ )
	{
		int n;
		cin>>n;
		char P[n];
		cin>>P;

		int S=0,C=0;
		int S_win = 0,C_win =0;
		for (int i=0;i<n;i++ )
		{
			if(P[i] == 'S')
			    S++;
            else
                C++;

            if(S == 4)
            {
                S_win++;
                S=0;
                C=0;
            }
            else if(C == 4)
            {
                C_win++;
                S=0;
                C=0;
            }
		}

		    cout<<S_win<<"-"<<C_win;
        if(S!=0 || C!=0)
		{
		    cout<<",";

            if(S == 0)
                cout<<"0";
		    else if(S == 1)
                cout<<"15";
            else if(S == 2)
                cout<<"30";
            else
                cout<<"40";

            cout<<"-";

            if(C == 0)
                cout<<"0";
            else if(C == 1)
                cout<<"15";
            else if(C == 2)
                cout<<"30";
            else
                cout<<"40";
		}
		cout<<"\n";
	}

}
