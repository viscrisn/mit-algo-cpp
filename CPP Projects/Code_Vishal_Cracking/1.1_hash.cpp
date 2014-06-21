#include <iostream>
#include <cstring>
#include <map>

using namespace std;

bool check_unique(string str)
{
	int len_str = str.length();
	map<char,bool> hash_table;

	for(int i=0;i<len_str;i++)
	{
		if(hash_table.count(str[i])>0)
			return false;
		hash_table.insert(pair<char,bool>(str[i],true));
	}
	return true;
}
int main()
{
	string str;
	getline(cin,str,'\n');
	//cin>>str;

	if(check_unique(str) == true)
		cout<<"All characters are unique";
	else
		cout<<"Duplicate characters are present";

	return 0;
}
