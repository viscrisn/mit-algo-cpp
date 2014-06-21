#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
#include<cmath>

using namespace std;

int binary_search(int A[], int key, int imin, int imax)
{
  if (imax < imin)
    return -1;
  else
    {
      int imid = (imin+imax)/2;

      if (A[imid] > key)
        return binary_search(A, key, imin, imid-1);
      else if (A[imid] < key)
        return binary_search(A, key, imid+1, imax);
      else
        return imid;
    }
}

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9};
    cout<<binary_search(a,4,0,8);
}
