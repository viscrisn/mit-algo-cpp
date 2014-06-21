#include<stdio.h>

int length,set;

int check(int frame[100],int ele)
{
    int i;
    for(i=0;i<length;i++)
        if(frame[i]==ele)
            return 1;
    return 0;
}

void set_pos(int frame[100],int flag[100],int val,int n)
{
    int i;
    for(i=0;i<n;i++)
        if(frame[i]==val && set<n-1)
        {
            set++;
            flag[i]=1;
        }
}

int get_pos(int flag[100],int n)
{
    int i;
    for(i=0;i<n;i++)
        if(flag[i]==0)
            return i;
    return -1;
}

void display(int frame[100])
{
    int i;
    for(i=0;i<length;i++)
        printf("%d   ",frame[i]);
}

void insert(int frame[100],int flag[100],int arr[100],int j,int n,int len,int *pf)
{
    int i,ele,pos;
    set=0;
    ele=arr[j-1];
    for(i=0;i<n;i++)
        flag[i]=0;
    if(check(frame,ele)==0)
    {
        printf("Y\t");
        if(length<n)
            frame[length++]=ele;
        else
        {
            for(;j<len;j++)
                set_pos(frame,flag,arr[j],n);
            pos=get_pos(flag,n);
            frame[pos]=ele;
        }
        (*pf)++;
    }
    else
        printf("N\t");
    display(frame);
}

int main()
{
    int i,len,n,pf,arr[100],frame[100],flag[100];
    length=pf=0;
    printf("Enter the no of pages in the reference string :-\t");
	scanf("%d",&len);
	printf("\nEnter the reference string :-\n");
	for(i=0;i<len;i++)
		scanf("%d",&arr[i]);
	printf("\nEnter the no. of frames :-   ");
	scanf("%d",&n);
	printf("\nPage No.\tPF\tFrames\n");
	for(i=0;i<len;i++)
	{
	    printf("\n   %d->\t\t",arr[i]);
	    insert(frame,flag,arr,i+1,n,len,&pf);
	}
	printf("\n\nNo. of Page Faults = %d\n",pf);
	return 0;
}
