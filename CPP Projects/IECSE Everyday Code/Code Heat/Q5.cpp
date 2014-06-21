#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
    int i,j;

    int n,sum;
    map<int,int> *newM;
    map<int,int> *valM,*valM2;
    map<int,int>::iterator iter;
    valM=valM2=NULL;
    char output[3000];

    sum=0;
    cin>>n;
    vector<int> a(n);
    int d[100]= {0};
    for(j=0; j<n; j++)
    {
        cin>>a[j];
    }
    sort(a.begin(), a.end());
    int f[451];
    int laste=450;
    for(j=0; j<n; j++)
    {
        sum+=a[j];
        d[j]=sum;
        for(int k=a[j]; k<=laste; k++)f[k]=j;
        laste=a[j]-1;
    }
    for(int k=0; k<=laste; k++)f[k]=j;
    int hsum=sum/2;
    valM = new map<int,int>;
    valM->operator[](0)=-1;
    //int tot=0;
    int nh1=n/2;
    int nh2=(n+1)/2;
    int best=0;
    //int tot=0;
    for(j=0; j<nh2 && best!=hsum; j++)
    {
        newM = new map<int,int>;
        int minrem = nh1-j-1;
        if(minrem<0)minrem=0;
        int maxrem = nh2-j-1;
        for(iter = valM->begin(); iter!=valM->end() && best!=hsum; iter++/*,tot++*/)
        {
            int pz=iter->first;
            int diff=hsum-pz;
            int diffi=(diff>450?0:f[diff]);
            i=max(diffi,iter->second+1);
            cout<<"*"<<pz<<","<<best<<","<<i<<"*";
            for(; i<n && best!=hsum; i++/*,tot++*/)
            {
                int z=pz+a[i];
                cout<<"#"<<z<<","<<best<<","<<i<<"#";
                if(minrem+i>=n) break;
                int maxS = z+d[i+maxrem]-d[i];
                if(maxS<=hsum)
                {
                    if(maxS>best) best=maxS;
                    break;
                }
                int minS = z+d[n-1]-d[n-1-minrem];
                if(minS>hsum)
                    continue;
                if(minS>best)
                    best=minS;
                if((newM->count(z)==0 || (*newM)[z]>i))
                {
                    (*newM)[z]=i;
                }
            }
        }
        //cout<<"#"<<j<<":"<<endl;
        //tot+=num;
        //delete valM;
        valM = newM;
    }
    //delete valM;
    //cout<<"total="<<tot<<";\n";
    static int op=0;
    //op+=sprintf(output+op,"%d %d\n\n",best,sum-best);
    cout<<best<<" "<<sum-best<<endl<<endl;
    cout<<output;
}
