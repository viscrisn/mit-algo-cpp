#include<iostream>

using namespace std;

struct si
{
    double a;
    double b;
    char g[45];
};

int main()
{
    double e;
    double *r=&e;
    cout<<sizeof(si);
    cout<<sizeof(r);
}
