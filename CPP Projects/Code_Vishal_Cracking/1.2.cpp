#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void reverse(char *str)
{
	int len_str = strlen(str);
	int limit = len_str/2;
	int first,last;
	for(first=0,last = len_str - 1 ; first<limit ; first++,last--)
		swap(str[first],str[last]);
	return;
}

int main()
{
	char str[1000];
	gets(str);

	reverse(str);
	printf("Reversed string is : %s",str);

	return 0;
}
