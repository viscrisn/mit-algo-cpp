#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

int main(){
int a[100],t,n,u;

cout<<"enter no. of elements";
cin>>n;

cout<<"enter the elements";
for(int i=0;i<n;i++){
    cin>>t;
    a[i]=t;
}

for(int j=2;j<n;j++)
{
    int i=j-1;
    for(;i>0;i--)
        {
        if(a[i+1]<a[i]){
            u=a[i];
            a[i]=a[i+1];
            a[i+1]=u;

        }
        else
        {
            break;
        }
    }
}

for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}


}
