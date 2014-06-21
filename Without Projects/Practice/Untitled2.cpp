// to-binary-bitops.cpp  Print binary representation of ints
// Fred Swartz  - 2001-09-04

#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        cout << "decimal: " << n << endl;

        // print binary with leading zeros
        cout << "binary : ";
        for (int i=31; i>=0; i--) {
            int bit = ((n >> i) & 1);
            cout << bit;
        }
        cout << endl;
    }//end loop
    return 0;
}//end main
