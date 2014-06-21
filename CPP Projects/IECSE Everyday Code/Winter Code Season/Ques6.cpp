#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<set>

using namespace std;

//Included more randomness by rolling a fair die.
//Lucky number gaurantees that people will have different santa each christmas
//( each time you run this code with same input, santa will choose a new person )
//Lucky group is created to break the symmetry.
//Its very boring when numbers start with 1 and ends with n
//better is random shuffleness.
//this randomness is achived, thanks to my die.


//Honestly, I have no idea what to do in this question.
//All method seems correct to me. lol

void random_shuffle(string a[], int n)
{
    int idx =0;
    for (int i=n-1; i>=0; i--)
    {
        idx = rand()%n;
        swap(a[i],a[idx]);
    }
}

int main()
{
    int n;
    cout<<"Enter number of persons trapped in this viscous cycle of sharing gifts\n";
    cin>>n;
    string a[n];
    cout<<"Enter the person's names\n";
    string temp = "";
    set<string> dup_chk;
    for (int i=0; i<n; i++)
    {
        cin>>temp;
        a[i].assign(temp);
        dup_chk.insert(a[i]);
    }

    if(dup_chk.size()!= n)
    {
        cout<<"Duplicate name inserted\n";
        return 0;
    }
    random_shuffle(a,n);

    if(n<=1)
    {
        cout<<"Lone Wolf\n";
        return 0;
    }

    int lucky_number = rand()%(n-1) + 1;
    int lucky_group = 3;//chosen after rolling a fair dice. Gauranteed to be random.

    for (int i=0;i<lucky_group;i++ )
    {
    	for (int j=i;j<n;j+=lucky_group )
    	{
    		cout<<a[j]<<" -> "<<a[(j + lucky_number)%n]<<"\n";
    	}

    }

}
