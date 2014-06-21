#include <iostream>
#include<cmath>
using namespace std;
struct Term
{
    double exponent;
    double coefficient;
};
double Area1(struct Term* equation,int noOfTerms,int limit1,int limit2)
{
    double area=0.0;
    for(int i=0;i<noOfTerms;i++)
    {
       equation[i].exponent++;
       equation[i].coefficient=equation[i].coefficient/equation[i].exponent;
    }
    for(int i=0;i<noOfTerms;i++)
    {
        area=area+equation[i].coefficient*(pow(limit2,equation[i].exponent));
    }
    for(int i=0;i<noOfTerms;i++)
    {
        area=area-equation[i].coefficient*(pow(limit1,equation[i].exponent));

    }
    return area;
}

int main()
{
    double area;
    struct Term equation[2];
    equation[0].exponent=2;
    equation[0].coefficient=1;
    equation[1].exponent=0;
    equation[1].coefficient=0;
	area=Area1(equation,1,1,3);
	cout<<area;
}
