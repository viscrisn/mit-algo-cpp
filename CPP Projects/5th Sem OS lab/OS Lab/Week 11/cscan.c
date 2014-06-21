#include<stdio.h>

int main()
{
	int arr[100],n,head,i,m,hm,min,max,ele,y;
	char dir;
	hm=y=0;
	min=999;
	max=-1;
	printf("\nEnter the total no of cylinders :-\t");
	scanf("%d",&n);
	printf("Enter the initial position of the read-write head :-\t");
	scanf("%d",&head);
	scanf("%c",&dir);
	printf("Enter the initial direction of the read-write head (L/R) :-\t");
	scanf("%c",&dir);
	printf("Enter the total no of IO block requests :-\t");
	scanf("%d",&m);
	printf("\nEnter the cylinder nos. for disk queue :-\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&ele);
		if(ele>=n)
		{
			printf("Not possible for %d\n",ele);
		}
		else
		{
			arr[y++]=ele;
		}
	}
	m=y;
	min=max=arr[0];
	for(i=0;i<m;i++)
	{
		if(dir=='L')
		{
			if(arr[i]<min)
				min=arr[i];
            if(max<head)
                max=arr[i];
			if(arr[i]<max && arr[i]>head)
				max=arr[i];
		}
		else
		{
			if(min>head)
                min=arr[i];
			if(arr[i]>min && arr[i]<head)
				min=arr[i];
			if(arr[i]>max)
				max=arr[i];
		}
	}

	if(dir=='L')
		hm+=head+(n-1-max);
	else
		hm+=(n-1-head)+min;
	printf("\nTotal Head Movements = %d\n",hm);
	return 0;
}
