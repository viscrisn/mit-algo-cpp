#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ifstream file;

    file.open("input01.txt");
    if(!file)
    {
        cout<<"Error\n";
        return 0;
    }

    int no_of_child =0;
    //cin>>no_of_child;
    file>>no_of_child;

    int ratings[no_of_child];

    for (int i=0;i<no_of_child;i++ )
    {
    	//cin>>ratings[i];
    	file>>ratings[i];
    }

    int candies[no_of_child];

    for (int i=0;i<no_of_child;i++ )
    {
    	candies[i]=1;
    }


    cout<<"\n";

    for (int i=1;i<no_of_child;i++ )
    {
    	if(ratings[i]>ratings[i-1])
    	{
    	    candies[i]+=candies[i-1];
    	}
    }

    for (int i=no_of_child;i>0;i-- )
    {
    	if((ratings[i]<ratings[i-1])&&
                (candies[i]>=candies[i-1]))
    	{
    	    candies[i-1]+=candies[i] - candies[i-1] + 1;
    	}
    }


    int total_candies=0;
    for (int i=0;i<no_of_child;i++ )
    {
    	total_candies+=candies[i];
    }

    cout<<total_candies;

}
