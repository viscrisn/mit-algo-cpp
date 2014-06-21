#include<iostream>
#include<cstring>

using namespace std;

void remove_duplicate(char *str)
{
	int len_str = strlen(str);
	if(str == '\0')
		return;
	else if(len_str<2)
		return;

	int tail = 1;
	for(int i = 0 ; i < len_str ; i++)
	{
	    int j = 0;
		for(j = 0 ; j < tail ; j++)
		{
			if(str[i]==str[j])
				break;
		}
		if (j == tail)
		{
			str[tail] = str[i];
			++tail;
		}
	}
	str[tail]='\0';
}

int main()
{
	char str[1000];
	cin>>str;
	remove_duplicate(str);
	cout<<str;
	return 0;
}
