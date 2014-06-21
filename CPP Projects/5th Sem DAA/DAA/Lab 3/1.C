#include<stdio.h>
#include<conio.h>

void selection(int arr[100],int n)
{
	int i,j,t,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[min]>arr[j])
				min=j;
		}
		t=arr[i];
		arr[i]=arr[min];
		arr[min]=t;
	}
}

void bubble(int arr[100],int n)
{
	int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
		}
	}
}

void display(int arr[100],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d  ",arr[i]);
	}
}

void main()
{
	int arr[100],n,i,ch;
	clrscr();
	printf("Enter the size of the array :-  ");
	scanf("%d",&n);
	printf("\nEnter the array elements :-\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\n\tMENU\n1) Selection Sort\n2) Bubble Sort\n3) Exit");
	while(1)
	{
		printf("\nEnter choice :-  ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("The array after selection sort is :-\n");
				selection(arr,n);
				display(arr,n);
				break;
			case 2:	printf("The array after bubble sort is :-\n");
				bubble(arr,n);
				display(arr,n);
				break;
			case 3:	exit(0);
		}
	}
}