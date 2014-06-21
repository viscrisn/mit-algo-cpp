/*
Question 2 of October Code Nights.

A number is said to be made up of non-decreasing digits if all the digits to the left of any digit is less than or equal to that digit. For example, the four-digit number 1234 is composed of digits that are non-decreasing. Some other four-digit numbers that are composed of non-decreasing digits are 0011, 1111, 1112, 1122, 2223. As it turns out, there are exactly
715 four-digit numbers composed of non-decreasing digits.

Notice that leading zeros are required: 0000, 0001, 0002 are all valid four-digit numbers with non-decreasing digits.

For this problem, you will write a program that determines how many such numbers there are with a specified number of digits.

Input
The first line of input contains a single integer P, (1<P<1000), which is the number of data sets that follow. Each data set is a single line that contains the data set number, followed by a space, followed by a decimal integer giving the number of digits N, (1<N<64).

Output
For each data set there is one line of output. It contains the data set number followed by a single space, followed by the number of N digit values that are composed entirely of non-decreasing digits.

Sample Input
3
1 2
2 3
3 4

Sample Output
1 55
2 220
3 715

*/


#include<iostream>

using namespace std;

int main()
{
    //Precalulations to make this algorithm run in constant time.
    long long a[11];
    long long b[64];
    int count=0;

    //Constant time loop (Independent of N)
    for(int i=0; i<11; i++)
    {
        a[i]=i;
    }
    //This for loop is independent of input, and runs in constant time.
    for (int j=0; j<61; j++ )
    {
        for (int i=1; i<11; i++ )
        {
            a[i] += a[i-1];
        }
        b[count++]=a[10];
    }
    //Constant time loop (Independent of N)
    for (int i=0;i<64;i++ )
    {
    	cout<<b[i]<<endl;
    }

    //Actual question starts here
    int test;
    cin>>test;
    while(test)
    {
        test--;
        int serial,n;
        cin>>serial>>n;
        cout<<serial<<" "<<b[n-2]<<"\n";
    }
}

//Efficiency of algorithm € O(1)
