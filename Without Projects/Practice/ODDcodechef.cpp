#include<iostream>

using namespace std;

    // 2^x <= N < 2^x+1; N>=1, x>=0
    // 2^x <- pos

    #include <cstdio>
    #include <cmath>

    int main()
    {

    int count, number;
    int result;

    scanf("%d", &count);

    for (int i=0;i<count;i++)
    {
    scanf("%d", &number);

    for (int j=0;;j++)
    {
    if ((number >= pow(2,j)) && (number < pow(2,j+1)))
    {
    result = (int)pow(2,j);
    printf("%d", result);
    printf("\n");
    break;
    }

    }
    }

    return 0;
    }


