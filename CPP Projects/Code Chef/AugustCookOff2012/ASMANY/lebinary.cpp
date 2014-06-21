#include<iostream>

using namespace std;

int main()
{
    int test;
    cin>>test;
    int array[]=
{
    1, 2,  4 ,  8 ,  16 ,  32 ,  64 ,  128 ,  256 ,  512 ,  1024 ,
    2048 ,  4096 ,  8192 ,  16384 ,  32768 ,  65536 ,  131072 ,  262144 ,
    524288 ,  1048576 ,  2097152 ,  4194304 ,  8388608 ,  16777216 ,
    33554432 ,  67108864 ,  134217728 ,  268435456 ,  536870912
};
    while (test>0)
    {
        test--;
        int num;
        cin>>num;
        int flag = 0;
        for (int i=0; i<(sizeof(array)/sizeof(int)); i++ )
        {
            if(array[i]==num)
            {
                flag = 1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }

    }
}
