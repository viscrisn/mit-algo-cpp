#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;
void redirect(ostream&);
int main()
{
    redirect(cout);
}
void redirect (ostream& strm)
{
filebuf buffer;
ostream output(&buffer);
istream input(&buffer);
buffer.open ("example.txt", ios::in | ios::out | ios::trunc);

int test,a,b,i,j,flag,k,i1;
cin>>test;
while(test!=0)
    {
    cin>>a>>b;
    if(a%2==0)
        {
            a=a+1;
        }
    else if(b%2==0)
    {
        b=b-1;
    }
    for(i=a;i<=b;i+=2)
        {
            if(i>3)
                {
                        flag=0;

                    k=sqrt(i);
                    for(i1=3;i1<=k;i1+=2)
                        {

                            if((i%i1)==0)
                                {
                                    flag=1;
                                    break;
                                }
                        }
                    if(flag==0)
                    {
                        cout<<i<<"\t";
                    output << i << " ,";
                    input.seekg(0);
                    char c;
                    while (input.get(c)) {


                    }
                    cout << endl;
                    input.clear();

                    }


                }
        }
    cout<<endl;
    test--;
}




}
