#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;


class is_negative
{
public:
   bool operator() (int value) const
   {
      return value < 0;
   }
};

int main()
{
	vector<int> array;
	int n;
	cin>>n;
	int temp;
	for (int i=0;i<n;i++ )
	{
		cin>>temp;
		array.push_back(temp);
	}

    int i;
    if(find_if(array.begin(),array.end(),is_negative())!= array.end())
    {
        cout<<"Yes, negative values are there";
    }
    else
    {
        cout<<"No, negative values are not present";
    }
}
