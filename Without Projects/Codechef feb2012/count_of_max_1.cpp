#include<iostream>

using namespace std;

int main()
{
    int t;
    int try1=0;

    cin>>t;

    int lar[t];
    int pos[t];
    for(int i=0;i<t;i++)
    {
        lar[i]=0;
        pos[i]=0;
    }

    for(int test=0;test<t;test++)
    {
        int len;
        cin>>len;

        int array[10001] = {0};

        int number[len];
        int largest=0;

        for(int i=0;i<len;i++)
        {
            cin>>number[i];
            if(number[i]>largest)
            {
                largest=number[i];
            }
            array[number[i]]++;
        }

        for(int i=0;i<len;i++)
        {
            if(lar[try1]<array[number[i]])
            {
                lar[try1]=array[number[i]];
                pos[try1]=number[i];
            }
        }
        try1++;

    }
    for(int i=0;i<t;i++)
    {
        cout<<pos[i]<<" "<<lar[i]<<endl;
    }
}
