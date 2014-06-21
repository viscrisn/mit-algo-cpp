    // calculate n to the power n (powers above 11!!)
    // note that 11^11 already exceeds unsigned long

#include <cmath>
#include <iostream>
#include<process.h>
#include<stdlib.h>

using namespace std;

int main()
{
    unsigned int nd, nz; // number of digits
    unsigned char *ca; // char array to hold result
    unsigned int j, n, q, temp;
    int i;
    double p;

    while(1)
    {
        cout << "\nEnter an integer to calculate n power n (0 to exit): ";
        cin >> n;

        if (n == 0) break;


        //calculate nd = the number of digits required
        // p is really nlog10(n)
        p = n*log10((double)n); // cast to double

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
        for (j = 1; j <= n; j++)
        {
            p += log10((double)n); // cast to double!!!
            nz = (int)p + 1; // number of digits to put into ca[]
            q = 0; // initialize remainder to be 0
            for (i = 0; i <= nz; i++)
            {
                temp = (ca[i] * n) + q;
                q = (temp / 10);
                ca[i] = (char)(temp % 10);
            }
        }

        cout << "\nThe nth power of " << n << " is: ";
        // the result is stored in reverse, spell it from the back
        for( i = nd - 1; i >= 0; i--)
        {
            cout << (int)ca[i];
        }
        cout << endl;

    // free up allocated memory
        delete []ca;
    } // while

}
