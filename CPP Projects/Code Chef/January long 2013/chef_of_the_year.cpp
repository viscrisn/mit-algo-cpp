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

struct chef
{
    string con, name;
    int votes, c_votes;
};

bool cmp_name(chef a,chef b)
{
    if(a.votes > b.votes)
        return true;
    else if(a.votes < b.votes)
        return false;
    else
    {
        if((a.name).compare(b.name) < 0)
            return true;
        else
            return false;
    }
}

bool cmp_con(chef a,chef b)
{

    if((a.con).compare(b.con) < 0)
        return true;
    else
        return false;

}

bool cmp_cvotes(chef a,chef b)
{
    if(a.c_votes > b.c_votes)
        return true;
    else if(a.c_votes < b.c_votes)
        return false;
    else
    {
        if((a.con).compare(b.con) < 0)
            return true;
        else
            return false;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    chef c[n];
    map <string,int> index;
    map<string, int>::iterator ii;

    for (int i=0; i<n; i++ )
    {
        cin>>c[i].name>>c[i].con;
        c[i].votes = 0;
        c[i].c_votes = 0;
        index.insert(pair<string, int>(c[i].name,i));
    }

    string email = "";
    int pos =0;
    for (int i=0; i<m; i++ )
    {
        cin>>email;
        ii = index.find(email);
        pos = (*ii).second;
        c[pos].votes++;
    }
/*
    for (int i=0;i<n;i++ )
    {
    	cout<<c[i].name<<"\t"<<c[i].con<<"\t"<<
    	c[i].votes<<"\t"<<c[i].c_votes<<"\t"<<"\n";
    }
    cout<<"\n\n\n";
*/
    sort(c,c+n,cmp_con);
    c[0].c_votes = c[0].votes;
    for (int i=1;i<n;i++ )
    {
    	if((c[i].con).compare(c[i-1].con)==0)
    	{
    	    c[i].c_votes = c[i-1].c_votes + c[i].votes;
    	}
    	else
    	{
    	    c[i].c_votes = c[i].votes;
    	}
    }
 /*
    for (int i=0;i<n;i++ )
    {
    	cout<<c[i].name<<"\t"<<c[i].con<<"\t"<<
    	c[i].votes<<"\t"<<c[i].c_votes<<"\t"<<"\n";
    }
    cout<<"\n\n\n";
*/
    sort(c,c+n,cmp_cvotes);
    cout<<c[0].con<<"\n";
/*
    for (int i=0;i<n;i++ )
    {
    	cout<<c[i].name<<"\t"<<c[i].con<<"\t"<<
    	c[i].votes<<"\t"<<c[i].c_votes<<"\t"<<"\n";
    }
    cout<<"\n\n\n";
*/
    sort(c,c+n,cmp_name);
    cout<<c[0].name<<"\n";
/*
    for (int i=0;i<n;i++ )
    {
    	cout<<c[i].name<<"\t"<<c[i].con<<"\t"<<
    	c[i].votes<<"\t"<<c[i].c_votes<<"\t"<<"\n";
    }
    cout<<"\n\n\n";
*/
}
