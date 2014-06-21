//1:45

#include<iostream>

using namespace std;

int sort(int b[],int n);
int fact(int);

int main()
{
    long n;
    int no_arr[20];
    cin>>n;
    int count=0;
    int no_of_z=0;
    int no_of_ele=0;

    while(n)
    {
        no_arr[count]=n%10;
        if(no_arr[count]==0)
        {
            count--;
            no_of_z++;
        }
        n=n/10;
        count++;
        no_of_ele++;
    }


   /*for(int i=0;i<count;i++)
    {
        if(no_arr[i]==0)
        {
            flag++;
        }
    }*/

    sort(no_arr,count);

   /* for(int i=0;i<count;i++)
    {
        cout<<no_arr[i]<<" ";
    }*/

    int total_sum=0;
    int val_z[10];
    int c=0;
    val_z[-1]=0;
    int same=1;

    for(int i=0;i<no_of_ele;i++)
    {
        if(no_arr[i]==no_arr[i+1])
        {
            same++;
        }
    }

        int no_of_ele1=0;
        //cout<<"val  "<<val_z[c-1]<<endl;
        for(int i=no_of_z;i>0;i--)
        {
            no_of_ele1=no_of_ele-i;
            val_z[c]=fact(no_of_ele1) - val_z[c-1];
           // cout<<"val  "<<val_z[c]<<endl;
            total_sum=fact(no_of_ele1) - val_z[c-1];
        }

        total_sum+=fact(no_of_ele - no_of_z);
        total_sum=(total_sum)/fact(same) - 1;
    cout<<total_sum<<endl;
    //cout<<no_of_ele<<endl;
    //cout<<fact((no_of_ele - 1));

}

int fact(int n)
{
    int k=1;
    for(int i=1;i<=n;i++)
    {
        k*=i;
    }
    return k;
}







int sort(int b[],int n)
{
    int temp;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(b[i]<b[j])
            {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
}
