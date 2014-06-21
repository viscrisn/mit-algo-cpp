#include <stdio.h>
//#include "areaundercurve.h"
#include<math.h>
#include<conio.h>
struct Term
{
    int exponent;
    int coefficient;
};
double f(int n,int x,struct Term* equation)
{
    double val=0.00;
    int i;
    for(i=0; i<n; i++)
        val+=equation[i].exponent * pow(x,equation[i].coefficient);
    return val;

}

double getAreaUnderCurve (struct Term* equation, int noOfTerms, int a,int b)
{
    double Area1, Area2;
    Area1 = (b-(a + b / 2)) * (f(noOfTerms,a+b/2,equation) +  f(noOfTerms,b,equation))/2;
    Area2 = ((a + b / 2)-a) * (f(noOfTerms,a+b/2,equation) +  f(noOfTerms,a,equation))/2;
    return (Area1+Area2);
}

int main()
{
    int noOfTerms = 2;
    struct Term *equation = (struct Term*)malloc(sizeof(struct Term) * noOfTerms);
    equation[0].exponent =2;
    equation[0].coefficient = 1;

    equation[1].exponent =2;
    equation[1].coefficient = 1;

    int limit1 = 1;
    int limit2 = 3;

    double usrout = getAreaUnderCurve(equation, noOfTerms, limit1, limit2);
    printf("%lf", usrout);
    getch();
}
