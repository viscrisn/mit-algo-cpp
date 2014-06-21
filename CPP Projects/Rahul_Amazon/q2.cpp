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

/*
*result = malloc(sizeof(int)*arr_size);
for(i =0; i<arr_size;i++) (*result)[i] = arr[i];
*/

int rearrange(int arr_size,int* arr, int *result)
{
    int neg_size = 0, pos_size = 0;
    int result_temp[arr_size];
    if(arr_size <= 0)
        return 0;
    for (int i=0; i<arr_size; i++ )
    {
        if(arr[i]<0)    neg_size++;
        else    pos_size++;
    }
    int neg_arr[neg_size];
    int pos_arr[pos_size];
    int neg_cur = 0;
    int pos_cur = 0;

    for (int i=0;i<arr_size;i++ )
    {
    	if(arr[i] < 0)
            neg_arr[neg_cur++] = arr[i];
        else
            pos_arr[pos_cur++] = arr[i];
    }
    neg_cur = 0;
    pos_cur = 0;

    int count = 0;
    if(arr[0] < 0)
    {
        result_temp[count++] = neg_arr[neg_cur++];
    }
    for (int i=0;i<arr_size;i++ )
    {
        if(pos_cur < pos_size)
            result_temp[count++] =pos_arr[pos_cur++];
        else
            break;
        if(neg_cur < neg_size)
            result_temp[count++] =neg_arr[neg_cur++];
        else
            break;
    }
    if(pos_cur >= pos_size)
    {
        while(neg_cur < neg_size)
            result_temp[count++] =neg_arr[neg_cur++];
    }
    else
    {
        while(pos_cur < pos_size)
            result_temp[count++] =pos_arr[pos_cur++];
    }

    for (int i=0;i<arr_size;i++ )
    {
    	cout<<result_temp[i]<<"\t";
    }



}

int main()
{
    int arr_size;
    cin>>arr_size;
    int arr[arr_size];
    for (int i=0;i<arr_size;i++ )
    {
    	cin>>arr[i];
    }
    int *result = (int*)malloc(sizeof(int)*arr_size);
    for(int i =0; i<arr_size;i++) result[i] = arr[i];
    rearrange(arr_size,arr,result);

}
