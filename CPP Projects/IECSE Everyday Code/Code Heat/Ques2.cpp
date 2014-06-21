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
#include<set>
#include<queue>
#include<fstream>


using namespace std;

int main()
{
    int L, U, B = 0;
    cin>>L>>U>>B;
    int button[B];
    for (int i = 0; i < B; i++)
        cin>>button[i];
    queue<int> q;
    int finish = 0;
    int cur[10000] = {};
    q.push(L);
    while (!q.empty())
    {
        int temp = q.front();
        int current = cur[temp];
        q.pop();
        if (temp == U)
        {
            cout<<current;
            finish = 1;
            break;
        }
        for (int i = 0; i < B; i++)
        {
            int second = (temp + button[i]) % 10000;
            if (!cur[second] && second != L)
            {
                q.push(second);
                cur[second] = current + 1;
            }
        }
    }
    if (!finish) cout<<"Permanently Locked";
}

//Vishal Krishna, Computer Science, 7th sem, MIT, Manipal
