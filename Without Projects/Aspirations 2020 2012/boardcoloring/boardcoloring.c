# include "boardcoloring.h"
#include<string.h>

int color(char board1[4][4])
{
    int i=0,j=0;
    int count_no =0;

	for(i=0;i<4;i++)
	{
	    for(j=0;j<4;j++)
	    {
	        if((board1[i][j]=='0')||(board1[i][j]=='1')||(board1[i][j]=='2')||(board1[i][j]=='3')||(board1[i][j]=='4')||(board1[i][j]=='5')||(board1[i][j]=='6')||(board1[i][j]=='7'))
	        {
	            count_no++;
	        }
	    }
	}
	if(count_no>=7)
        return 5;
    else
        return 4;
}
