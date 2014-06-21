#include<iostream>
#include<algorithm>

using namespace std;

//Working
int main()
{
    int n;
    cin>>n;
    int group[n];
    for (int i=0; i<n; i++)
    {
        cin>>group[i];
    }
    sort(group,group+n);
    int two_left=0,one_left=0;
    int front=0,back=n-1;
    long long ans = 0;
    while(front <= back)
    {
        if(group[back] == 4)
            ans++;
        else if(group[back] == 3)
        {
            if(group[front]==1)
            {
                front++;
            }
            ans++;
        }
        else if(group[back]==2)
            two_left++;
        else if(group[back]==1)
            one_left++;
        back--;
    }
    ans += two_left/2;
    ans += one_left/4;
    one_left %= 4;
    two_left %= 2;
    if(two_left!=0)
    {
        ans++;
        one_left -= 2;
    }
    if(one_left > 0) ans++;
    cout<<ans;
}
