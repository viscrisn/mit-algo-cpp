#include <iostream>
#include <cstring>

#define FOR(i,a,b) for (__typeof(a) i=(a); i != (b); ++i)

using namespace std;

int LEFT[30001];
int RIGHT[30001];
int ARRAY[100001];

int center(int A[], int I, int mid, int J)
{
    int ans = 0;
    int a,b,c;
    memset(LEFT,0,120004);
    memset(RIGHT,0,120004);
    FOR(i,I,mid) ++LEFT[A[i]];
    FOR(i,mid,J) ++RIGHT[A[i]];

    FOR(i,I,mid)
    {
        FOR(j,i+1,mid)
        {
            a = A[i];
            b = A[j];
            c = b+b-a;
            if (c < 30001 && RIGHT[c])
                ans += RIGHT[c];
        }
    }
    FOR(i,mid,J)
    {
        FOR(j,i+1,J)
        {
            b = A[i];
            c = A[j];
            a = b+b-c;
            if (a < 30001 && LEFT[a])
                ans += LEFT[a];
        }
    }
    return ans;
}

int solve(int A[], int i, int j)
{
    int n = j-i;
    if (n < 3)
        return 0;
    int mid = n/2;
    int a = solve(A,i,i+mid);
    int b = solve(A,i+mid,j);
    int c = center(A,i,i+mid,j);
    int ans = a+b+c;
    return ans;
}

int main()
{
    int N;
    cin>>N;
    FOR(i,0,N)
    {
        cin>>ARRAY[i];
    }
    cout<<solve(ARRAY,0,N)<<"\n";
    return 0;
}
