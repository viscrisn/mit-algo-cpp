#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int n;
    cin>>n;

    string buffer[n];
    int count[n];

    int counter =0;
    int flag =0;

    /*for (int i=0; i<n; i++ )
    {
        count[i]=1;
    }*/
    string temp;

    for (int i=0; i<n; i++ )
    {
        flag = 0;
        cin>>temp;
        for(int j=0; j<counter; j++)
        {
            if(temp.length() == buffer[j].length())
            {
                if(temp.compare(buffer[j])==0)
                {
                    flag = 1;
                    count[j]++;
                    break;
                }
            }
        }
        if(flag==0)
        {
            buffer[counter] = temp;
            count[counter] = 1;
            counter++;
        }
    }

    int k=0;
    cin>>k;
    int largest=0;
    int index = 0;

    for (int j=0; j<k; j++ )
    {
        index =0;
        largest = 0;
        for (int i=0; i<counter; i++ )
        {
            if(count[i]>largest)
            {
                largest = count[i];
                index = i;
            }
            else if(count[i]==largest &&
                    (buffer[index].compare(buffer[i])>0))
            {
                index = i;
            }
        }
        cout<<buffer[index]<<"\n";
        count[index]=0;
    }



}

