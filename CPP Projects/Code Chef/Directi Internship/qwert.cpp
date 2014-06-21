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

int count1[4];
string a;
int ans,idx,bt[2];
int single;
int len;
int found =0;
string str[5];
int idx_prev;

void count_val()
{
    a[len] = '2';
    a[len+1] = '\0';
    for (int i=1; i<len; i++ )
    {
        if(a[i]=='0' && a[i-1]=='0')
        {
            if(a[i+1]=='0')
                i++;
            count1[0]++;
        }
        else if(a[i]=='1' && a[i-1]=='0')
        {
            count1[1]++;
        }
        else if(a[i]=='0' && a[i-1]=='1')
        {
            count1[2]++;
        }
        else if(a[i]=='1' && a[i-1]=='1')
        {
            if(a[i+1]=='1')
                i++;
            count1[3]++;
        }
    }
}
int max_index()
{
    int max=0;
    int idx=0;
    for (int i=0; i<4; i++ )
    {
        if(count1[i]>max)
        {
            max = count1[i];
            idx = i;
        }
    }
    return idx;

}
void bit_change()
{
    if(idx!=idx_prev)
    {


        if(idx ==0)
        {
            ans+=count1[0];
            if(bt[0]==1)
            {
                bt[0]=0;
                ans++;
            }
            if(bt[1]==1)
            {
                bt[1]=0;
                ans++;
            }
        }
        else if(idx==1)
        {
            ans+=count1[1];
            if(bt[0]==1)
            {
                bt[0]=0;
                ans++;
            }
            if(bt[1]==0)
            {
                bt[1]=1;
                ans++;
            }
        }
        else if(idx==2)
        {
            ans+=count1[2];
            if(bt[0]==0)
            {
                bt[0]=1;
                ans++;
            }
            if(bt[1]==0)
            {
                bt[1]=1;
                ans++;
            }
        }
        else if(idx==3)
        {
            ans+=count1[3];
            if(bt[0]==0)
            {
                bt[0]=1;
                ans++;
            }
            if(bt[1]==0)
            {
                bt[1]=1;
                ans++;
            }
        }
    }
}
void count_single()
{
    if(a[0]!='2'&&a[1]=='2')
    {
        ans++;
        a[0] = '2';
    }
    for (int i=1; i<len; i++ )
    {
        if(a[i-1]=='2' && a[i+1]=='2' && a[i]!='2')
        {
            ans++;
            a[i] = '2';
        }
    }
}

void std_proc()
{
    idx = max_index();
    bit_change();
    single =0;
    count_single();
    for (int i=0; i<count1[idx]; i++ )
    {
        found = a.find(str[idx]);
        a.replace(found,2,str[4]);
    }
    for (int i=0; i<4; i++ )
    {
        count1[i] = 0;
    }
    count_val();
}
int main()
{
    int test;
    cin>>test;

    for(int testno = 0; testno < test ; testno++ )
    {
        //char a[220];

        cin>>a;
        len = a.length();
        a[len] = '2';
        a[len+1] = '\0';
        ans = 0;
        bt[0] = 0;
        bt[1] = 0;

        for (int i=0; i<4; i++ )
        {
            count1[i] = 0;
        }
        count_val();

        idx = max_index();
        bit_change();

        str[0] = "00";
        str[1] = "01";
        str[2] = "10";
        str[3] = "11";
        str[4] = "22";
        for (int i=0; i<count1[idx]; i++ )
        {
            found = a.find(str[idx]);
            a.replace(found,2,str[4]);
        }

        single =0;
        count_single();
        for (int i=0; i<4; i++ )
        {
            count1[i] = 0;
        }
        count_val();
        idx_prev = idx;
        std_proc();
        idx_prev = idx;
        std_proc();
        idx_prev = idx;
        std_proc();

        cout<<ans-1;
    }
}
