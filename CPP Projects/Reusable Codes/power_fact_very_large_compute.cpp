#include <cmath>
#include <iostream>
#include<stdlib.h>

using namespace std;

int fact(unsigned int);
int power(int n);

int fact(unsigned int n)
{
    unsigned int nd, nz; // number of digits
    unsigned char *ca; // char array to hold result
    unsigned int j, q, temp;
    int i;
    double p;

        if (n == 0) return 0;

        //calculate nd = the number of digits required
        p = 0.0;
        // p is really log10(n!)
        for(j = 2; j <= n; j++)
        {
            p += log10((double)j); // cast to double
        }

        nd = (int)p + 1;
        // allocate memory for the char array
        ca = new unsigned char[nd];
        if (!ca)
        {
            cout << "Could not allocate memory!!!";
            exit(0);
        }
        //initialize char array
        for (i = 1; i < nd; i++)
        {
            ca[i] = 0;
        }
        ca[0] = 1;

        // put the result into a numeric string using the array of characters
        p = 0.0;
        for (j = 2; j <= n; j++)
        {
            p += log10((double)j); // cast to double!!!
            nz = (int)p + 1; // number of digits to put into ca[]
            q = 0; // initialize remainder to be 0
            for (i = 0; i <= nz; i++)
            {
                temp = (ca[i] * j) + q;
                q = (temp / 10);
                ca[i] = (char)(temp % 10);
            }
        }

        //cout << "\nThe Factorial of " << n << " is: ";
        // the factorial is stored in reverse, spell it from the back
        for( i = nd - 1; i >= 0; i--)
        {
            cout << (int)ca[i];
        }
        cout << endl;

    // free up allocated memory
        delete []ca;

    return 0;
}

int main()
{
    int t;
    cin>>t;
    int cse=0;
    int fac[t];

    for(int i=0;i<t;i++)
    {
        int num;
        cin>>num;
        fact(num);
    }
}
