//Brute Force

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<functional>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector< vector <long long> > points;

    points.resize(n, vector<long long> (2));

    for (int i=0; i<n; i++ )
    {
        for (int j=0; j<2; j++ )
        {
            cin>>points[i][j];
        }
    }

    long long distance =99999999;
    for (int j=0; j<n; j++ )
    {
        long long dist =0;
        for (int i=0; i<n; i++ )
        {
            dist += abs(points[i][0]-points[j][0])>abs(points[i][1]-points[j][1])?abs(points[i][0]-points[j][0]):abs(points[i][1]-points[j][1]);
        }
        if(dist < distance)
            distance = dist;
    }
    cout<<distance;

}

