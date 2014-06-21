/*
ID: viscris1
PROB: gift1
LANG: C++
*/

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

int main()
{
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
    map<string, int> m;
    map<string, int>::iterator ii;

    map<int , string> t;
    map<int , string>::iterator it;

    int np;
    cin>>np;
    string s;
    for (int i=0; i<np; i++ )
    {
        cin>>s;
        m.insert(pair<string, int>(s,i));
        t.insert(pair<int, string>(i,s));
    }
    /*
    for (it=t.begin(); it != t.end(); it++ )
    {
        cout<<(*it).first<<" "
            <<(*it).second<<"\n";
    }
    */

    int money[np];
    memset(money,0,np*4);
    int money_fnl[np];
    memset(money_fnl,0,np*4);

    int mny,per;
    int idm,idp;
    for (int i=0; i<np; i++ )
    {
        cin>>s;
        cin>>mny>>per;

        ii = m.find(s);

        idm = (*ii).second;
        money_fnl[idm] = mny;
        if(per!=0)
            money[idm] += mny%per;
        else
            money[idm] += mny;

        for (int j=0; j<per; j++ )
        {
            cin>>s;
            ii = m.find(s);
            idp = (*ii).second;

            money[idp] += mny/per;
        }

    }
    for (int i=0; i<np; i++ )
    {
        money_fnl[i] = money[i] - money_fnl[i];
    }

    for (it = t.begin(); it != t.end(); it++ )
    {
        s = (*it).second;
        ii = m.find(s);
        cout<<(*ii).first<<" "
            <<money_fnl[(*ii).second]<<"\n";
    }





}
