#include<stdio.h>

int main()
{
	int arr[100],flag[100],n,head,i,m,hm,diff,count,temp,index,ele,y;
	hm=count=y=0;
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
			flag[y]=0;
			y++;
		}
	}
	m=y;
	while(count!=m)
	{
		diff=999;
		index=-1;
		for(i=0;i<m;i++)
		{
			if(flag[i]==0)
			{
				temp=head-arr[i];
				if(temp<0)
					temp=-temp;
				if(temp<diff)
				{
					diff=temp;
					index=i;
				}
			}
		}
		flag[index]=1;
		hm+=diff;
		count++;
		head=arr[index];
	}
	printf("\nTotal Head Movements = %d\n",hm);
	return 0;
}
