#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<sstream>
#include<queue>
#include<cstdlib>
#include<map>
#include<set>

using namespace std;


class GreatFairyWar
{
public:
    int minHP(vector <int> dps, vector <int> hp)
    {
        int len = dps.size();
        int cul_dps[len];
        cul_dps[len-1] = dps[len-1];

        int damage=0;
        for (int i=len-2;i>=0;i-- )
        {
        	cul_dps[i] = dps[i] + cul_dps[i+1];
        }

        for (int i=0;i<len;i++ )
        {
        	damage += cul_dps[len-i-1]*hp[len-i-1];
        	//cout<<cul_dps[len-i-1]<<"*"<<hp[len-i-1]<<endl;
        }


        return damage;
    }
};

int main()
{
    GreatFairyWar a;
    vector <int> c;
    vector <int> d;
    /*for (int i=0;i<3;i++ )
    {
    	c.push_back(i+5);
    }
    for (int i=0;i<3;i++ )
    {
    	d.push_back(2);
    }*/
    c.push_back(1);
    c.push_back(2);

    d.push_back(3);
    d.push_back(4);
    cout<<a.minHP(c,d);
}




