#include<stdio.h>

int main()
{
	int arr[100],n,head,i,m,hm,head_min,head_max,min,max,ele,y;
	char dir;
	hm=y=0;
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
	head_min=head_max=min=max=arr[0];
	for(i=0;i<m;i++)
	{
		if(arr[i]<min)
            min=arr[i];
        if(arr[i]>max)
            max=arr[i];
        if(dir=='L')
		{
			if(arr[i]<head_min)
				head_min=arr[i];
            if(head_max<head)
                head_max=arr[i];
			if(arr[i]<head_max && arr[i]>head)
				head_max=arr[i];
		}
		else
		{
			if(head_min>head)
                head_min=arr[i];
			if(arr[i]>head_min && arr[i]<head)
				head_min=arr[i];
			if(arr[i]>head_max)
				head_max=arr[i];
		}
	}

	if(dir=='L')
		hm+=(head-min)+(max-head_max);
	else
		hm+=(max-head)+(head_min-min);
	printf("\nTotal Head Movements = %d\n",hm);
	return 0;
}
