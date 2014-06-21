#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        char stop='a';
        int count[53]={0};

        while(stop!='\n')
        {
            cin>>stop;

            if(stop<91){}
            if(stop=='\n')
            {
                break;
            }
        }
        cout<<'a'<<" "<<'z'<<" "<<'A'<<" "<<'Z';
    }
}
