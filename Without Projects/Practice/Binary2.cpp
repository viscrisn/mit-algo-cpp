#include <iostream.h>
#include<conio.h>

int binary(int);

int main(int) {
	int number;

	cout << "Please enter a positive integer: ";
	cin >> number;
    cout << number << " converted to binary is: ";
    binary(number);
    cout << endl;
}

int binary(int number) {
	int remainder;

	if(number <= 1) {
		cout << number;
		return;
	}

	remainder = number%2;
	binary(number >> 1);
	cout << remainder;
}
