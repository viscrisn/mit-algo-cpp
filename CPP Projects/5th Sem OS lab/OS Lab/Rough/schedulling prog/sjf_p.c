#include<stdio.h>
#include<stdlib.h>

struct proc{
	int at;
	int tat;
	int wt;
	int bt;
	int tbt;
	int tt;
	int p;
	int flag;
	int pid;
}s[10],temp;



int alldone(int n){
	int i=0;
	for(i=0;i<n;i++){
		if(s[i].flag!=1)	return 0;
	}
	return 1;
}
		

void main()
{
	int n,i,j,time,curr[100],k,ttt,twt,least;
	ttt=twt=k=time=0;
	printf("Enter Number of Processes :-\t");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the process ID :- ");
		scanf("%d",s[i].pid);
		printf("Enter the arrival time of process %d :- ",P[i].pid);
		scanf("%d",&s[i].at);
        printf("Enter the burst time of process %d :- ",P[i].p);
        scanf("%i",&s[i].bt);
		s[i].p=0;
		s[i].flag=0;
		s[i].tbt=s[i].bt;
		s[i].tat=s[i].at;
		s[i].wt=0;
		s[i].tt=0;
	}


	while(alldone(n)!=1){
		k=0;
		for(i=0;i<n;i++){	
			if(s[i].at<=time && s[i].bt>0)	curr[k++]=i;
		}

		if(k>0){
			least=curr[0];
			for(i=0;i<k;i++){	if(s[curr[i]].bt<s[least].bt)	{least=curr[i];}	}
			s[least].wt+=time-s[least].at;
			s[least].bt--;
			time++;
			s[least].at=time;
	
			if(s[least].bt==0){
				s[least].flag=1;
				s[least].tt=time-s[least].tat;						
			}
		}
		else	time++;
	}		

	for(i=0;i<n;i++){
		ttt+=s[i].tt;
		twt+=s[i].wt;
	}

	
	for(i=0;i<n;i++)
	{
		printf("\nProcess : %d",P[i].p);
		printf("\nWaiting Time : %d",P[i].wt);
		printf("\nTurn Around Time : %d\n",P[i].tat);
	}
	printf("\nAverage Waiting Time = %.2f",(float)twt/n);
	printf("\nAverage Turn Around Time = %.2f",(float)ttt/n);
	
}

