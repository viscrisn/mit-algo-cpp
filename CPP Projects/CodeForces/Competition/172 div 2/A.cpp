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
#include<set>
#include<queue>
#include<fstream>

using namespace std;

int main()
{
	string a;
	cin>>a;
	if(islower(a[0]))
	a[0] = toupper(a[0]);

	cout<<a;
}
