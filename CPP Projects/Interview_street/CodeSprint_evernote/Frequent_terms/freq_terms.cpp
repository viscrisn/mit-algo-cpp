#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n][2];
    int counter =0;
    int flag =0;
    //char temp[32]={0};
    //int temp;
    for(int i=0;i<n;i++)
    {
        a[i][1]=0;
        a[i][0]=0;
    }

    for (int i=0;i<n;i++ )
    {
        flag = 0;
        char temp[32]={0};
     	cin>>temp;
    	for(int j=0;j<counter;j++)
    	{
    	    if((temp==(char*)a[j][0]))
    	    {
    	        flag = 1;
    	        a[j][1]++;
     	        break;
    	    }
    	}
    	if(flag == 0)
    	{
    	    a[counter][0] = *temp;
    	    a[counter][1] = 1;
    	    counter++;
    	}
    }

    for (int i=0;i<counter;i++ )
    {
        char temp[32] = {0};
        *temp = a[i][0];
    	cout<<temp<<"\t"<<a[i][1]<<"\n";
    }



}
