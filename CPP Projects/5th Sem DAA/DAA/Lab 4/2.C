#include<stdio.h>
#include<conio.h>

int BinarySearch(int arr[100],int n,int key)
{
	int l,r,m;
	l=0;
	r=n-1;
	while(l<=r)
	{
		m=(l+r)/2;
		if(key==arr[m])
			return m;
		else if(key<arr[m])
			r=m-1;
		else
			l=m+1;
	}
	return -1;
}

void main()
{
	int arr[100],n,key,i,pos;
	clrscr();
	printf("\nEnter the total no. of elements :- ");
	scanf("%d",&n);
	printf("\nEnter the array elements in sorted order :- ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		while(arr[i]<arr[i-1] && i>0)
		{
			printf("Enter the array in sorted order only.\nPlease re-enter the array element :- ");
			scanf("%d",&arr[i]);
		}
	}
	printf("\nEnter the element to be searched for :- ");
	scanf("%d",&key);
	pos=BinarySearch(arr,n,key);
	if(pos>=0)
		printf("\nThe element found at %dth position",(pos+1));
	else
		printf("\nElement Not Found...");
	getch();
}