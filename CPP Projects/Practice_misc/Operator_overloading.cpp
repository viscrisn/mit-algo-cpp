#include<iostream>

using namespace std;

class Points
{
private:
    float x;
    float y;
public:
    Points(float x_cor,float y_cor)
    {
        x = x_cor;
        y = y_cor;
    }
    float get_x()
    {
        return x;
    }
    float get_y()
    {
        return y;
    }
    Points operator+(const Points &p2)
    {
        Points temp(x+p2.x,y+p2.y);
        return temp;
    }
};
int main()
{
    Points p1(3.1,4.5);
    Points p2(5.7,6.2);
    cout<<"Point\t"<<"X\t"<<"Y\n";
    cout<<"p1\t"<<p1.get_x()<<"\t"<<p1.get_y()<<"\n";
    cout<<"p2\t"<<p2.get_x()<<"\t"<<p2.get_y()<<"\n";
    Points p3 = p1 + p2;//even p1 = p1 + p2 or p2 = p1 + p2 will work
    cout<<"p3\t"<<p3.get_x()<<"\t"<<p3.get_y()<<"\n";
}
