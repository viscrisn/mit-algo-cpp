#include<stdio.h>
#include<conio.h>

void insertion_sort(int a[],int n)
{
	int i,j,next,k;
	for(i=1;i<n;i++)
	{
		next=a[i];
		for(j=i-1;j>=0&&next<a[j];j--)
		{
			a[j+1]=a[j];
			for(k=0;k<n;k++)
				printf("%d  ",a[k]);
			printf("\n");
		}
		a[j+1]=next;
		printf("\n");
	}
}

void main()
{
	int a[10],n,i;
	clrscr();
	printf("\nEnter the size of the array :-	");
	scanf("%d",&n);
	printf("\nEnter the array elements :-\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	insertion_sort(a,n);
	printf("\nThe sorted array is :-	");
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}
	getch();
}