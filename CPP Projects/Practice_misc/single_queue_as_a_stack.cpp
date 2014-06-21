#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<functional>
#include<stack>
#include<queue>

using namespace std;

int stk_pop(queue<int> &Q)
{
    int len = Q.size();
    int temp;
    for (int i=0;i<len-1;i++ )
    {
    	temp = Q.front();
    	Q.pop();
    	Q.push(temp);
    }
    temp = Q.front();
    Q.pop();
    return temp;

}
int main()
{
    queue<int> Q;

    while(1)
    {
        cout<<"1.push\n2.pop\n3.Exit\n";
        int menu;
        cin>>menu;
        switch(menu)
        {
            case 1:
                int t;
                cout<<"Enter number:\t";
                cin>>t;
                Q.push(t);
                break;
            case 2:
                cout<<stk_pop(Q)<<"\n";
                break;
            case 3:
                exit(0);
                break;
            default:
                cout<<"Wrong option selected\n";
        }
    }
}
