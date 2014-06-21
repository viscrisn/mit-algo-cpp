#include<stdio.h>
#include<conio.h>

int Partition(int a[100],int l,int r)
{
	int p,i,j,temp;
	p=a[l];
	i=l+1;
	j=r;
	while(1)
	{
		while(i<r && a[i]<=p)	i++;
		while(p<a[j])	j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		else
		{
			temp=a[l];
			a[l]=a[j];
			a[j]=temp;
			return j;
		}
	}
}

void QuickSort(int a[100],int l,int r)
{
	int s;
	if(l<r)
	{
		s=Partition(a,l,r);
		QuickSort(a,l,s-1);
		QuickSort(a,s+1,r);
	}
}

void main()
{
	int a[100],n,i;
	clrscr();
	printf("\nEnter the total no. of elements :- ");
	scanf("%d",&n);
	printf("\nEnter the array elements :-\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	QuickSort(a,0,n-1);
	printf("\nThe sorted array is :-\n");
	for(i=0;i<n;i++)
		printf("%d",a[i]);
	getch();
}