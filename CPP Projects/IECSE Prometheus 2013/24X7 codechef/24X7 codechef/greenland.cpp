#include<iostream>
#include<vector>
#include<deque>

#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

int n,a[200005],i,j,x,y,us[200005]= {0},p=0,r[200005]= {0};
vector<pair<int,int> > v[200005];


int main()
{
    int test;
    cin>>test;

    for(int testno = 0; testno < test ; testno++ )
    {
        deque<int> d;
        cin>>n;
        for(i=1; i<n; i++)
        {
            cin>>x>>y;
            v[x].pb(mp(y,0));
            v[y].pb(mp(x,1));
        }
        d.pb(1);
        us[1]=1;
        while(d.size())
        {
            i=d[0];
            d.pop_front();
            for(j=0; j<v[i].size(); j++)
            {
                if(!us[v[i][j].F]) p+=v[i][j].S,d.pb(v[i][j].F),us[v[i][j].F]=1;
            }
        }
        d.pb(1);
        us[1]=2;
        r[1]=p;
        while(d.size())
        {
            i=d[0];
            d.pop_front();
            p=min(p,r[i]);
            for(j=0; j<v[i].size(); j++)
            {
                if(us[v[i][j].F]==1)

                {
                    r[v[i][j].F]=r[i];
                    if(v[i][j].S==1) r[v[i][j].F]--;
                    else r[v[i][j].F]++;
                    d.pb(v[i][j].F);
                    us[v[i][j].F]=2;
                }
            }
        }
        cout<<p<<endl;
        for(i=1; i<=n; i++)
        {
            if(r[i]==p) cout<<i<<" ";
        }
        cout<<"\n";
    }
}
