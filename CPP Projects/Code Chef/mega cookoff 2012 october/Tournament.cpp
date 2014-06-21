#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>

using namespace std;

int main()
{
	int test;
	cin>>test;
	while(test)
	{
	    test--;
	    int n,m,p;
	    cin>>n>>m>>p;

	    float *pos1 = (float*)(calloc(n,sizeof(float)));

	    for (int i=0;i<n;i++ )
	    {
	    	pos[i] = 0;
	    }

	    int misc;

	    for (int i=0;i<m;i++ )
	    {
	        cin>>misc;
	    	pos[misc-1] = 1;
	    }

        float *pos1 = (float*)(calloc(n/2,sizeof(float)));
        int count =0;
	    for (int i=0;i<n;i+=2 )
	    {
            if(pos[i] && pos[i+1])
            {
                pos1[count++] = 1;
            }
            else if(pos[i] || pos[i+1])
            {
                pos1[count++] = p;
            }
            else
            {
                pos1[count++] = 0;
            }
	    }
        free(pos);

        for (int i=0;i<;i++ )
        {

        }

	}
}
