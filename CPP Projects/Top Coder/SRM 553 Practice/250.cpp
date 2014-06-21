#include<iostream>

using namespace std;

class PlatypusDuckAndBeaver
{
    public:
    int minimumAnimals(int wf, int db, int bt)
    {
        //duck -     1db,    2wf
        //beaver -       1bt,4wf
        //platypus - 1db,1bt,4wf

        int x = (wf - 4*bt)/2;
        int y = (db - x);
        int z = (bt - y);
        return x+y+z;
    }

};

int main()
{
    FoxAndFlowerShopDivTwo a;
    //cout<<a.theMaxFlowers("asd",2,2);
}
