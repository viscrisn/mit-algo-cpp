#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
{
int number;
int count = 0;
cout<< "This program finds out if the number you enter is a prime"<<endl;
cout<<"Enter a number to test: ";
cin>>number;
int i;
cout<<"the factors of "<<number<<" are: "<<endl;
for(i = 2; i <=number; i++){
if((number%i) ==0){
count =count+1;
cout<<i<<" ";

}
}
cout<<endl;
if (count==1){
cout<<number<<" is a prime."<<endl;
}
else
cout<<number<<" is not a prime. It has "<<count<<" factors.\n";

return(0);
}
