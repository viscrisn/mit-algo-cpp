#include<iostream>

using namespace std;

char temp[50];
int digits;
void cal_digits(int n)
{
    digits = 1;
    while(n!=0)
    {
        n/=10;
        digits++;
    }
}
void number(int num)
{
    for(int i =digits-1; i>= 0; i--)
    {
        if(num == 0)
        {
            temp[i] = '0';
            continue;
        }
        temp[i] = (num%10) + 48;
        num /= 10;
    }
    temp[digits]='\0';

}


int main()
{
    int n;
    cin>>n;
    cal_digits(n);
    int nsq = n*n;
    int arr[nsq];
    int mat[n][n];

    for(int i=0; i<nsq; i++)
    {
        arr[i] = i+1;
    }

    int r1_lvl;
    int r1_start;
    int r1_end;

    int c1_lvl;
    int c1_start;
    int c1_end;

    int r2_lvl;
    int r2_start;
    int r2_end;

    int c2_lvl;
    int c2_start;
    int c2_end;
    int count=0;

    r1_start =0;
    r1_lvl =0;
    r1_end = n;

    c1_start = 1;
    c1_end =n;
    c1_lvl = n-1;

    r2_start = n-2;
    r2_end = 0;
    r2_lvl = n-1;

    c2_lvl = 0;
    c2_start = n-2;
    c2_end = 1;

    int iter =0;
    while(iter!=n/2)
    {


        for (int i=r1_start; i<r1_end; i++ )
        {
            mat[i][r1_lvl] = arr[count++];
        }
        r1_start++;
        r1_end--;
        r1_lvl++;



        for (int i=c1_start; i<c1_end; i++ )
        {
            mat[c1_lvl][i] = arr[count++];
        }
        c1_start++;
        c1_end--;
        c1_lvl--;


        for (int i=r2_start; i>=r2_end; i-- )
        {
            mat[i][r2_lvl] = arr[count++];
        }
        r2_start--;
        r2_end++;
        r2_lvl--;


        for (int i=c2_start; i>=c2_end; i-- )
        {
            mat[c2_lvl][i] = arr[count++];
        }
        c2_start--;
        c2_end++;
        c2_lvl++;

        iter++;

    }
    for (int i=0; i<n; i++ )
    {
        for (int j=0; j<n; j++ )
        {
            number(mat[j][i]);
            cout<<temp;
        }
        cout<<"\n";

    }

}
