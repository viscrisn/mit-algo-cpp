#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<numeric>
#include<sstream>
#include<string>
#include<cmath>
#include<algorithm>
#include<stack>

using namespace std;

int t[105][105],a[105],n;
int arr[105],limit;

//This function will return the optimal sum of weights
//i.e., int the given sample test case, it would return 151
//This will also initialize our arr array with indexes
//of books which comtribute to this optimal weight
int solve(int s,int e,int left,int curm,int maxm)
{
    if(left==0)
        if(curm<=maxm)
            return curm;
        else
            return 0;
    if(curm>maxm||(e-s+1)<left)
        return 0;
    if(t[n-left][n-1]+curm>maxm)
        return 0;
    int cur=0;
    int temp = 0;
    for(int i=s; i<=e; i++)
    {
        if(cur>0&&t[i][i+left-1]+curm<=cur)
            return cur;

        temp = solve(i+1,e,left-1,curm+a[i],maxm);
        if(cur < temp)
        {
            cur = temp;
            arr[limit++] = i;
        }
        //Now we have some repeated, but optimal indexes in arr
        //which helps to add to total weight of one pile of books
        if(cur==maxm)
            return cur;
    }
    return cur;
    //cur will contain the weight of 1 plie
}
int main()
{
    int i,j,q,k,m;
    scanf("%d",&n);
    int sum=0;
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    //Input the weights and sorting and reversing
    sort(a,a+n);
    reverse(a,a+n);
    for(i=0; i<n; i++)
    {
        int prev=0;
        for(j=i; j<n; j++)
        {
            t[i][j]=prev+a[j];
            prev=t[i][j];
        }
    }
    //Initialization of t
    //Used dynamic programming to help speed up the process
    //of getting the optimal weight of 1 pile in solve()

    int half=sum/2,ans,ans1=0;
    if(n%2)
    {
        ans1=solve(0,n-1,(n+1)/2,0,half);
    }
    ans=solve(0,n-1,n/2,0,half);
    ans=max(ans,ans1);
    //"ans" has optimal weight distribution
    //sum - ans will be close to ans
    //sum - ans is weight of other pile

    printf("%d %d\n\n",ans,sum-ans);

    //code to retrieve the books
    //could have been more efficient, but since
    //time complexity is O(n^2), this works fine
    reverse(arr,arr+limit);
    int arr2[limit],limit2 = 0;
    for (int i=0;i<limit;i++)
    {
        for (int j=i+1;j<limit;j++ )
    	{
    	    if(arr[i]==arr[j])
    	    {
    	        arr[j] = -1;
    	        break;
    	    }
    	}
    }
    //arr2 has books of 1 pile
    for (int i=0;i<limit;i++ )
    {
    	if(arr[i] != -1)
            arr2[limit2++] = arr[i];
    }
    int sum1 = 0;
    //Checks if weight of 1 pile equals to optimal weight
    //calculated before in ans variable
    for (int i=0; i<limit2; i++ )
    {
        if(sum1!=ans&&sum1!=sum-ans)
            sum1 += a[arr2[i]];
        else
        {
            limit2 = i;
            break;
        }
    }
    //Just getting the size of pile
    if(limit2 > (n/2+1))
        limit2 = n/2+1;

    for (int i=0; i<limit2; i++ )
    {
        cout<<a[arr2[i]]<<"\t";
    }
    //Displaying pile 1
    cout<<"\n";
    int flag = 0;

    //Code to diplay remaining books
    //which belongs to pile 2
    for (int i=0; i<n; i++ )
    {
        flag = 0;
        for (int j=0;j<limit2;j++ )
        {
        	if(arr2[j]==i)
        	{
        	    flag = 1;
        	    break;
        	}

        }
        if(flag == 0)
            cout<<a[i]<<"\t";
    }
    //Done

    return 0;
}

/*
total number of books=n;
total weight = k;
this question is the same as choosing n/2 books
and their sum weights should be as close as k/2;

initialize a set t
-while(true):
1.try to replace each book in t with each book outside,
and choose the pair that make the difference of the sum and k/2 minimal
Time Complexity - O(n/2 * n/2).
2. record the difference "ans".
break if the difference of all pairs > D
*/

//Vishal Krishna, Computer Science, MIT
