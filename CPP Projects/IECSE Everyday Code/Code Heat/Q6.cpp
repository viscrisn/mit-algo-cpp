#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int max_words = 80;
char bag_of_words[max_words][max_words];
int length[max_words];

int solve(int size_i, int size_j)
{
    int ans = 0;
    int M = length[size_j], N = length[size_i];
    char *s1 = bag_of_words[size_i];
    char *s2 = bag_of_words[size_j];
    for(int i = 0; i < M; ++i)
    {
        int cnt = 0;
        int k = i;
        for(int j = 0; j < N; ++j)
        {
            if(k >= M) k = 0, cnt = 0;
            if(s1[j] == s2[k]) cnt++;
            ans = max(ans, cnt);
            k++;
        }
    }
    return ans;
}

int main()
{
    int total_count, n, ans;
    cin>>total_count;
    while(total_count-- > 0)
    {
        cin>>n;
        for(int i = 0; i < n; ++i)
        {
            cin>>bag_of_words[i];
            length[i] = strlen(bag_of_words[i]);
        }
        ans = 0;
        for(int i = 0; i < n - 1; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                ans = max(ans, solve(i, j));
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
