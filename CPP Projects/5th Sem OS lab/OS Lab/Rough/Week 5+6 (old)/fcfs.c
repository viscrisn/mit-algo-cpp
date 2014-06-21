#include<stdio.h>
struct proc
{
	int p;
	int arr;
	int bur;
	int ct;
	int wt;
	int tat;
}P[10];


int main()
{
	int n,i,j;
	float avg_wt,avg_tat;
	avg_wt=avg_tat=0.0;
	struct proc temp;
	printf("\nEnter the no. of processes :- ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the process ID :- ");
		scanf("%d",&(P[i].p));
		printf("Enter the arrival time of process %d :- ",P[i].p);
		scanf("%d",&(P[i].arr));
		printf("Enter the burst time of process %d :- ",P[i].p);
		scanf("%d",&(P[i].bur));
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(P[i].arr>P[j].arr)
			{
				temp=P[i];
				P[i]=P[j];
				P[j]=temp;
			}
		}
	}
	
	P[0].ct=P[0].bur-P[0].arr;
	P[0].tat=P[0].ct-P[0].arr;
	P[0].wt=P[0].tat-P[0].bur;
	printf("\nThe Order of execution of processes is :-\nP%d  ",P[0].p);
	for(i=1;i<n;i++)
	{
		printf("P%d  ",P[i].p);
		P[i].ct=P[i-1].ct+P[i].bur;
		P[i].tat=P[i].ct-P[i].arr;
		P[i].wt=P[i].tat-P[i].bur;
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		avg_wt+=P[i].wt;
		avg_tat+=P[i].tat;
	}
	avg_wt/=n;
	avg_tat/=n;
	
	for(i=0;i<n;i++)
	{
		printf("\nProcess : %d",P[i].p);
		printf("\nWaiting Time : %d",P[i].wt);
		printf("\nTurn Around Time : %d\n",P[i].tat);
	}
	printf("\nAverage Waiting Time = %.3f",avg_wt);
	printf("\nAverage Turn Around Time = %.3f",avg_tat);
	
	return 0;
}
