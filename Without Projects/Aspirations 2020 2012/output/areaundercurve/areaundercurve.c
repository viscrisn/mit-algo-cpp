#include <stdio.h>
#include "areaundercurve.h"
#include<math.h>
#include<conio.h>

double getAreaUnderCurve (struct Term* equation,int noOfTerms,int limit1,int limit2)
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


