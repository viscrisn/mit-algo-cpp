#include<stdio.h>

struct proc{
	int arr;
	int tat;
	int wt;
	int bur;
	int tt;
	int p;
	int flag;
	int pid;
}s[10],temp;



int completed(int n){
	int i=0;
	for(i=0;i<n;i++){
		if(s[i].flag!=1)	return 0;
	}
	return 1;
}
		

int main(){

	int n,i,time,curr[100],k,ttt,twt,least;
	k=ttt=twt=time=0;
	printf("\nEnter the no. of processes :- ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the process ID :- ");
		scanf("%d",&(s[i].pid));
		printf("Enter the arrival time of process %d :- ",s[i].pid);
		scanf("%d",&(s[i].arr));
		printf("Enter the burst time of process %d :- ",s[i].pid);
		scanf("%d",&(s[i].bur));
		printf("Enter the priority level of process %d :- ",s[i].pid);
		scanf("%d",&(s[i].p));
		s[i].flag=0;
		s[i].tat=s[i].arr;
		s[i].wt=0;
		s[i].tt=0;
	}

	printf("\n\nThe Order of execution of processes per unit time is :-\n");
	while(completed(n)!=1)
	{
		k=0;
		for(i=0;i<n;i++){	
			if(s[i].arr<=time && s[i].bur>0)	curr[k++]=i;
		}

		if(k>0)
		{
			least=curr[0];
			for(i=0;i<k;i++)
				if(s[curr[i]].p<s[least].p)
					least=curr[i];	
			s[least].wt+=time-s[least].arr;
			s[least].bur--;
			time++;
			s[least].arr=time;
	
			if(s[least].bur==0)
			{
				s[least].flag=1;
				s[least].tt=time-s[least].tat;						
			}
			printf("P%d  ",s[least].pid);
		}
		else
			time++;
	}		
	printf("\n");
	for(i=0;i<n;i++){
		ttt+=s[i].tt;
		twt+=s[i].wt;
		printf("\nProcess : %d",s[i].pid);
		printf("\nWaiting Time : %d",s[i].wt);
		printf("\nTurn Around Time : %d\n",s[i].tt);
	}
	
	printf("\nAverage Waiting Time = %.2f",(float)twt/n);		
	printf("\nAverage Turn Around Time = %.2f",(float)ttt/n);
	return 0;
}

