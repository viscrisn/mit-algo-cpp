#include<iostream>
#include<math.h>

using namespace std;
float cal_distance(int p1,int p2,int p3,int p4)
{
    float ans=0;
    ans = sqrt(pow((p1 - p3),2)  +  pow((p2 - p4),2));

    if(ans==0)
        return 99999;

    return ans+16;
}



int main()
{


    int n;
    cin>>n;
    int answer=0;

    int mat[n][3];
    for (int i=0; i<n; i++ )
    {
        mat[i][2]=0;
    }

    for (int i=0; i<n; i++ )
    {
        for (int j=0; j<2; j++ )
        {
            cin>>mat[i][j];
        }
    }

    float dist[n][n];
    for (int i=0; i<n; i++ )
    {
        for (int j=0; j<n; j++ )
        {
            dist[i][j] = cal_distance(mat[i][0],
                                      mat[i][1],
                                      mat[j][0],
                                      mat[j][1]);
        }

    }

    float ans[n][n];
    for (int i=0; i<n; i++ )
    {
        for (int j=0; j<n; j++ )
        {
            ans[i][j] = 0;
        }
    }

    for (int i=0; i<n; i++ )
    {
        for (int j=0; j<n; j++ )
        {
            cout<<dist[i][j]<<"\t";
        }
        cout<<endl;

    }
    cout<<endl;

    for(int k=0; k<n; k++)
    {


        float min =99999;
        int outer =0,inner =0 ;
        int ab=0,cd=0;
        for (outer=0; outer<n; outer++ )
        {
            for (inner=0; inner<n; inner++ )
            {
                if(dist[outer][inner]<min)
                {
                    min = dist[outer][inner];
                    ab=outer;
                    cd=inner;
                }
            }
        }
        for (int i=0;i<n;i++ )
        {
        	dist[ab][i]=99999;
        }


        ans[ab][cd] = min;

        dist[ab][cd] = 99999;
        dist[cd][ab] = 99999;
        /*for (int i=0; i<n; i++ )
        {
            for (int j=0; j<n; j++ )
            {
                cout<<dist[i][j]<<"\t";
            }
            cout<<endl;

        }*/
        cout<<endl;

    }
    float total =0;
    for (int i=0;i<n;i++ )
    {
    	for (int j=0;j<n;j++ )
    	{
    		if(ans[i][j]!=0)
    		{
    		    total+=ans[i][j];
    		    cout<<i<<"\t"<<j<<"\t"<<ans[i][j];
    		}
    		cout<<"\n";
    	}
    	cout<<endl;
    	cout<<total;

    }

/*
    for (int i=0; i<n; i++ )
    {
        for (int j=0; j<n; j++ )
        {
            cout<<dist[i][j]<<"\t";
        }
        cout<<endl;

    }

    cout<<endl;
    for (int i=0; i<n; i++ )
    {
        for (int j=0; j<n; j++ )
        {
            cout<<ans[i][j]<<"\t";
        }
        cout<<endl;

    }*/




}

