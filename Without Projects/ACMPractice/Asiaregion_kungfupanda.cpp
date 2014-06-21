/*18 mins, working (test cases addtion took 5-8 mins) */
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int t=n;
    int x=1;
    int row[50][10];
    int col[50][10];
    while(n)
    {

        cin>>row[0][x];
        for(int i =1;i<=row[0][x];i++)
        {
            cin>>row[i][x];
        }

        cin>>col[0][x];
        for(int i =1;i<=col[0][x];i++)
        {
            cin>>col[i][x];
        }
        x++;
        n--;
    }
    x=1;
    while(t)
    {
        cout<<"Case: "<<x<<endl;
        cout<<row[0][x]<<endl;
        for(int i=1;i<=row[0][x];i++)
        {
            cout<<row[i][x]<<", "<<col[i][x]<<endl;
        }
        x++;
        t--;
    }

}
