#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>

//1st quadrant, integer values.
//No constraints were mentioned in the question, so assuming this.
// Otherwise, just translate all the rectangles to first quadrant and run this algorithm.


using namespace std;


//If you remove the code in comments, the algorithm will be self explanatory.
//Easiest(simplest) method in my opinion
//Checking for all cases using loops and conditions will be more space efficient, but this is kind-of space-time tradeoff.
//if your coordinates are large, declare global matrix
//it can handle size of a[100000][100000]
//I hope your input is not larger than that.
//Waiting for the next question :)


int main()
{
    int xmin,xmax,ymin,ymax;
    cout<<"Largest Rectangle\n";
    cout<<"Enter xmin, ymin, xmax, ymax\n";
    cin>>xmin>>ymin>>xmax>>ymax;
    int range_x = xmax - xmin,range_y = ymax - ymin;
    bool mat[range_x][range_y];
    for (int i=0; i<range_x; i++ )
    {
        for (int j=0; j<range_y; j++ )
        {
            mat[i][j] = true;
        }
    }
    //remove this comment to make the code self explanatory when you run

    /*for (int i=0; i<range_x; i++ )
    {
        for (int j=0; j<range_y; j++ )
        {
            cout<<mat[i][j]<<"\t";
        }
        cout<<"\n";
    }*/

    while(1)
    {
        cout<<"Enter -1 to end, 0 to add smaller triangle\n";
        int key;
        cin>>key;
        if(key == -1)
        {
            break;
        }
        int x1,x2,y1,y2;
        cout<<"Smaller Rectangle\n";
        cout<<"Enter xmin, ymin, xmax, ymax\n";
        cin>>x1>>y1>>x2>>y2;
        for (int i=x1 - xmin; i<x2 - xmin; i++ )
        {
            for (int j=y1 - ymin; j<y2 - ymin; j++ )
            {
                mat[i][j] = false;
            }
        }
        /*for (int i=0; i<range_x; i++ )
        {
            for (int j=0; j<range_y; j++ )
            {
                cout<<mat[i][j]<<"\t";
            }
            cout<<"\n";
        }*/
    }
    int count=0;
    for (int i=0; i<range_x; i++ )
    {
        for (int j=0; j<range_y; j++ )
        {
            if(mat[i][j] == true)
                count++;
        }
    }
    cout<<"Area is:\t"<<count;
}
