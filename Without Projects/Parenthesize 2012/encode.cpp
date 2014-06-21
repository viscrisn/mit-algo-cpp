#include<iostream>

using namespace std;

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


    int j=0;
    int no_arr1[10];
    for(int i=no_of_ele - 1 ;i>=0;i--)
    {
        no_arr1[i]=no_arr[j];
        j++;
    }

    /*for(int i=0;i<no_of_ele;i++)
    {
        cout<<no_arr1[i]<<" ";
    }*/
    int j1=0;
    int final[10];
    no_arr1[-1]=0;
    int matter=0;
   /* for(int i=0;i<no_of_ele;i++)
    {
        if(no_arr1[i]!=1)
        {
            matter=0;
            cout<<i<<" ecxi ";
            break;

        }
        else if(no_arr1[i]!=2)
        {
            matter=0;
            cout<<i<<" ecxi ";
            break;
        }
        else
        {
            matter=1;
        }
    }
    if(matter==1)
    {
        if(no_of_ele%2==1)
        {
            final[0]=no_arr1[no_of_ele - 1];
            j1++;
        }
    }*/
    int count123=0;
    int pos;
 /*   for(int i=0;i<no_of_ele;i++)
    {
        if(no_arr1[i]==1&&(no_arr1[i-1]==1||no_arr1[i-1]==2))
        {
            count123++;
            pos=i;
        }
        if(no_arr1[i]==2&&(no_arr1[i-1]==1||no_arr1[i-1]==2))
        {
            count123++;
            pos=i;
        }
    }
    if(count123>=2)
    {
        final[j1]=no_arr1[pos];
        j1++;
    }*/

    for(int i=0;i<no_of_ele;i++)
    {
        if(no_arr1[i]==1)
        {
            i=i+1;
        }
        else if(no_arr1[i-1]==1)
        {
            continue;
        }
        else if(no_arr1[i]==2 && no_arr1[i+1]<6)
        {
            i=i+1;
        }
        else if(no_arr1[i-1]==2 && no_arr1[i]<6)
        {
            continue;
        }
        else if(no_arr1[i]==0 && no_arr1[i-1]!=1||no_arr1[i-1]!=2)
        {
            final[0]=14;
            final[1]=15;
            final[2]=14;
            final[3]=5;
            j1=4;
            break;
        }
        else
        {
            final[j1++]=no_arr1[i];
        }
}
        if(j1==0)
        {
            if(no_of_ele%2==1)
            {
                final[0]=no_arr1[no_of_ele - 1];
                j1++;
            }
        }


   /* cout<<endl;
    for(int i=0;i<no_of_ele;i++)
        {
            cout<<no_arr1[i]<<" ";
        }
   */
    cout<<endl;

    for(int i=0;i<j1;i++)
        {
            cout<<char(final[i]+64);
        }





}
