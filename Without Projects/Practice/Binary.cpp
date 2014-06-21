#include <iostream>
using namespace std;
int binary(int);
int main() {
    int no1,no2,arno1[33],arno2[33],sum[33];
        cin>>no1>>no2;


//converting two nos into binary
        binary(no1);
        cout << "binary : ";
        for (int i=31; i>=0; i--) {
            int bit = ((no1 >> i) & 1);
            arno1[i]=bit;
            cout << arno1[i];
        }
        cout << endl;

        cout << "binary : ";
        for (int i=31; i>=0; i--) {
            int bit = ((no2 >> i) & 1);
            arno2[i]=bit;
            cout << arno2[i];
        }
        cout << endl;
//conversion done
//addition
        for (int i=31;i>=0;i--){
            if (((arno1[i]==0)&&arno2[i]==0)||(((arno1[i])==1)&&arno2[i]==1))
            {
                sum[i]=0;
            }

            else if (arno1[i]==1||arno2[i]==1)
                sum[i]=1;

            cout<<sum[i];
        }
//addition done

}

int binary(int n){
    int h[33];
            cout << "binary : ";
        for (int i=31; i>=0; i--) {
            int bit = ((n >> i) & 1);
            h[i]=bit;
            cout << h[i];

        }
        return h[33];
        cout << endl;

}
