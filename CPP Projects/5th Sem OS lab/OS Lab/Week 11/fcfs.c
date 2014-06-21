#include<stdio.h>

int main()
{
	int arr[100],n,head,i,m,hm,diff,ele,y;
	hm=y=0;
	printf("\nEnter the total no of cylinders :-\t");
	scanf("%d",&n);
	printf("Enter the initial position of the read-write head :-\t");
	scanf("%d",&head);
	printf("Enter the total no of IO block requests :-\t");
	scanf("%d",&m);
	printf("\nEnter the cylinder nos. for disk queue in arrival order :-\n");
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
	for(i=0;i<m;i++)
	{
		diff=head-arr[i];
		if(diff<0)
            diff=-diff;
        hm+=diff;
		head=arr[i];
	}
	printf("\nTotal Head Movements = %d\n",hm);
	return 0;
}
