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

    for (int i=0;i<n;i++ )
	{
		for (int j=0;j<2;j++ )
		{
			cin>>points[i][j];
		}
	}

    double x_sum = 0,y_sum =0;
    for (int i=0;i<n;i++ )
	{
			x_sum += points[i][0];
			y_sum += points[i][1];
	}
	x_sum/=n;
	y_sum/=n;
	double min = 99999999;
	double max =0;
	int min_index[n];
	int k=0;
    for (int i=0;i<n;i++ )
	{
	    max = (points[i][0] - x_sum)>(points[i][1] - y_sum)?abs(points[i][0] - x_sum):abs(points[i][1] - y_sum);
			if(min >= max)
			{
			    min = max;
			    min_index[k++] = i;
			}
	}

	for (int j=0;j<k;j++ )
	{
		cout<<points[min_index[j]][0]<<" "<<points[min_index[j]][1]<<"\n";
	}


    long long distance =9999999;

for (int j=0;j<k;j++ )
{
    long long dist =0;
    for (int i=0;i<n;i++ )
    {
    	dist += abs(points[i][0]-points[min_index[j]][0])>abs(points[i][1]-points[min_index[j]][1])?abs(points[i][0]-points[min_index[j]][0]):abs(points[i][1]-points[min_index[j]][1]);
    }
    if(dist < distance)
        distance = dist;
}
    cout<<distance<<"\n";

	for (int i=0;i<n;i++ )
	{
		for (int j=0;j<2;j++ )
		{
			cout<<points[i][j]<<"\t";
		}
		cout<<"\n";
	}

}
