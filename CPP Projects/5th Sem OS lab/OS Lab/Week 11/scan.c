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
			arr[y]=ele;
			if(arr[y]<min)
				min=arr[y];
			if(arr[y]>max)
				max=arr[y];
			y++;
		}
	}
	m=y;
	scanf("%c",&dir);
	printf("Enter the initial direction of the read-write head (L/R) :-\t");
	scanf("%c",&dir);
	if(dir=='L')
		hm+=head+max;
	else
		hm+=(n-1-head)+(n-1-min);
	printf("\nTotal Head Movements = %d\n",hm);
	return 0;
}
