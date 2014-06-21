#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> tree[200001];
vector<int> dir[200001];
int rootcnt;
int cnt[200001];

int dfs1(int v, int p)
{
	int c = 0;
	for (int i=0;i<tree[v].size();i++)
		if (tree[v][i] != p)
			c += (dir[v][i] < 0 ? 1 : 0) + dfs1(tree[v][i],v);
	return c;
}

void dfs2(int v, int p,int c)
{
	cnt[v] = c;
	for (int i=0;i<tree[v].size();i++)
		if (tree[v][i] != p)
			dfs2(tree[v][i],v,c - (dir[v][i] < 0 ? 1 : -1));
}

int main()
{

	int n,a,b;
	cin>>n;
	for (int i=0;i<n-1;i++)
	{
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
		dir[a].push_back(1);
		dir[b].push_back(-1);
	}

	rootcnt = dfs1(1,-1);
	dfs2(1,-1,rootcnt);
	int mn = *min_element(cnt+1,cnt+n+1);
	cout<<mn<<endl;
	for (int i=1;i<=n;i++)
		if (cnt[i] == mn)
			cout<<i<<" ";
	cout<<endl;
	return 0;
}
