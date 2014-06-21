#include<stdio.h>

int length;

int check(int frame[100],int ele)
{
    int i;
    for(i=0;i<length;i++)
        if(frame[i]==ele)
            return 1;
    return 0;
}

void display(int frame[100])
{
    int i;
    for(i=0;i<length;i++)
        printf("%d   ",frame[i]);
}

void insert(int frame[100],int ele,int n,int *pf,int *front)
{
    if(check(frame,ele)==0)
    {
        printf("Y\t");
        if(length<n)
            frame[length++]=ele;
        else
        {
            frame[(*front)]=ele;
            (*front)=((*front)+1)%n;
        }
        (*pf)++;
    }
    else
        printf("N\t");
    display(frame);
}

int main()
{
    int i,len,n,pf,front,arr[100],frame[100];
    length=pf=front=0;
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
	    insert(frame,arr[i],n,&pf,&front);
	}
	printf("\n\nNo. of Page Faults = %d\n",pf);
	return 0;
}
