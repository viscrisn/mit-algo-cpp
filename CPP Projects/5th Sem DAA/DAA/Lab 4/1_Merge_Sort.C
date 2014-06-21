#include<stdio.h>
#include<conio.h>

void Merge(int a[],int l,int m,int h)
{
	int i,j,k,c[100];
	i=k=l;
	j=m+1;
	while(i<=m && j<=h)
	{
		if(a[i]<a[j])
		{
			c[k]=a[i];
			i++;
		}
		else
		{
			c[k]=a[j];
			j++;
		}
		k++;
	}
	while(i<=m)
		c[k++]=a[i++];
	while(j<=h)
		c[k++]=a[j++];
	for(i=l;i<=h;i++)
		a[i]=c[i];
}

void MergeSort(int a[],int l,int h)
{
	int m;
	if(l<h)
	{
		m=(l+h)/2;
		MergeSort(a,l,m);
		MergeSort(a,m+1,h);
		Merge(a,l,m,h);
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
	MergeSort(a,0,n-1);
	printf("\nThe sorted array is :-\n");
	for(i=0;i<n;i++)
		printf("%d",a[i]);
	getch();
}