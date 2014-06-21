#include <math.h>
#include <iostream>

using namespace std;

double f(double x)
{
	return x;
}

double integrate(double a,double b,int N)
{
	double h = (b - a) / N;
	double sum = 0.5 * h * (f(a) + f(b));
 for (int k = 0; k < N; k++)
		sum += h * f(a + h*k);
	return sum;
}

double area_under_curve(double a,double b)
{
	double area = integrate(a,b,1000);
	double check = integrate(a,b,5);
	if (abs(area - check) > 0.00000000001)
		{
			double m = (a + b) / 2;
			area = area_under_curve(a, m) + area_under_curve(m, b);
		}
	return area;
}
int main()
{
	cout<<"Integral of x.dx from 0 to 2 is : "<<integrate(0,2,1000)<<endl;
	cout<<"Area Under the Line y=x from 0 to 4 is : "<<area_under_curve(0,4);
	return 0;
}
