/*
S -> TL
T -> int|float
L -> L,id | id

S -> TL
T -> int|float
L -> idL'
L' -> ,idL' | e

Sample Input (Space after every character)
int a , b , c ;
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void T();
void Ldash();
void L();

char a[100], token[200];
int count = 0, m = 1, len = 0;

void getNextToken()
{
	int i = 0;
	/*if (len >= strlen (a))
	{
		cout << "Error!";
		exit(0);
	}*/
	if (m == 1) {
	while (a[len] == ' ' && (len < strlen (a)))
		len++;

	while (a[len] != ' ' && (len < strlen (a)))
	{
		token[i++] = a[len];
		len++;
	}
	len++;
	token[i] = '\0';
	cout << token << endl;
	m= 0;
	}
}

char match()
{
	m = 1;
}

void S()
{
	T();
	L();
	getNextToken();
	if (token[0] == ';')
	{
		match();
	}
	else
	{
		cout << "Error in S\n";
		exit(1);
	}
}

void T()
{
	getNextToken();
	if (strcmp(token, "int") == 0 || strcmp (token, "float") == 0)
	{
		match();
	}
	else
	{
		cout << "Error in T";
		exit(1);
	}
}

void L()
{
	getNextToken();
	if (token[0] >= 'a' && token[0] <= 'z')
	{
		match();
		Ldash();
	}
	else
	{
		cout << "Error in L";
		exit(1);
	}
}

void Ldash()
{
    getNextToken();
	if (token[0] == ',')
	{
		match();
		getNextToken();
		if (token[0] >= 'a' && token[0] <= 'z')
		{
			match();
			Ldash();
		}
		else
		{
			cout << "Error in Ldash!";
			exit(1);
		}
	}
}

int main()
{
	int result = 0;
	cout << "Enter String : ";
	cin.getline( a, 100, '\n');
	S();
	cout << "Correctly Parsed!\n";
	return 0;
}

