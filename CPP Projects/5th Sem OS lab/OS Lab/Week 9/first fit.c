#include<stdio.h>

struct partitions
{
	int part_size;
	int rem_part;
	int proc[10];
	int cp;
}P[20];

int main()
{
	int n,i,m,pro[20],j,flag;
	printf("\nEnter the no. of partitions :-  ");
	scanf("%d",&n);
	printf("\nEnter the partition sizes :-\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&P[i].part_size);
		P[i].rem_part=P[i].part_size;
		P[i].cp=0;
	}
	
	printf("\nEnter the no. of processes :-  ");
	scanf("%d",&m);
	
	printf("\nEnter the processes size :-\n");
	for(i=0;i<m;i++)
	{
		printf("Process %d :-  ",i);
		scanf("%d",&pro[i]);
	}
	printf("\n\n.......... FIRST FIT ..........\n\n");
	for(i=0;i<m;i++)
	{
		flag=1;
		for(j=0;j<n;j++)
		{
			if(pro[i]<=P[j].rem_part)
			{
				P[j].rem_part-=pro[i];
				P[j].proc[++(P[j].cp)]=pro[i];
				flag=0;
				break;
			}
		}
		if(flag==1)
			printf("\nProcess %d with process size %d cannot be accomodated now...",i,pro[i]);
	}
	
	printf("\n\nThe details of the processes which have been accomodated are given below :-");
	printf("\n\nPartition Size\tPartition Remaining\tProcesses\n");
	for(i=0;i<n;i++)
	{
		printf("\n\t%d \t\t%d \t\t",P[i].part_size,P[i].rem_part);
		for(j=1;j<=P[i].cp;j++)
		{
			printf("%d    ",P[i].proc[j]);
		}
	}
	
	return 0;
}
