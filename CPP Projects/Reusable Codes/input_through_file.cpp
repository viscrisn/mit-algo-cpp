//OR YOU CAN USE THIS:
//freopen("beautiful_stringstxt","r",stdin);
//freopen("beautiful","w",stdout);

/*
ALTERNATE METHOD IS:-

ifstream file;

    file.open("test.csv");
    if(!file)
    {
        cout<<"Error\n";
        return 0;
    }
    for(int j=0; j<262588; j++)
    {
        file>>test[j];
    }

*/
#include<iostream>
#include<fstream>

using namespace std;

ifstream::pos_type size;

char * memblock;

int main()
{
    ifstream file("train.csv",ios::in|ios::binary|ios::ate);
    if(file.is_open())
    {
        size = file.tellg();
        memblock = new char [size];
        file.seekg(0,ios::beg);
        file.read(memblock,size);
        file.close();
        cout<<"Complete block is in memory now.\n";
        //delete[] memblock;
    }
    else
    {
        cout<<"Unable to open file";
        return 0;
    }

}
