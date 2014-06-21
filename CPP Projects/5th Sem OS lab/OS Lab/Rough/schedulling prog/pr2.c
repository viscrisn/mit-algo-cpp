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
	char pname[20];
}s[10],temp;



int alldone(int n){
	int i=0;
	for(i=0;i<n;i++){
		if(s[i].flag!=1)	return 0;
	}
	return 1;
}
		

void main(){

	int n,i,j;
	printf("\n\n Priority Scheduling : Pre-Emptive ");
	printf("\n\n Enter Number of Processes : ");
	scanf("%d",&n);
	printf("\n Enter Details : ");
	for(i=0;i<n;i++){
		printf("\n   Process Name - ");
		scanf("%s",s[i].pname);
		printf("\n   Process Arrival time - ");
		scanf("%i",&s[i].at);
                printf("\n   Process Burst time - ");
                scanf("%i",&s[i].bt);
		printf("\n   Process Priority - ");
                scanf("%i",&s[i].p);
		s[i].flag=0;	s[i].tbt=s[i].bt;	s[i].tat=s[i].at;	s[i].wt=0;	s[i].tt=0;
	}

	int time=0;
	int curr[100];
	int k=0,ttt=0,twt=0,least;

	while(alldone(n)!=1){
		k=0;
		for(i=0;i<n;i++){	
			if(s[i].at<=time && s[i].bt>0)	curr[k++]=i;
		}

		if(k>0){
			least=curr[0];
			for(i=0;i<k;i++){	if(s[curr[i]].p<s[least].p)	{least=curr[i];}	}
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


	printf("\n\n\nP Name\tArv Time\tBurst Time\tWaiting Time\tTurn A. Time");
	printf("\n------\t--------\t----------\t------------\t------------\n");

	for(i=0;i<n;i++){
		printf("\n%s  \t    %d    \t    %d     \t     %d      \t     %d      ",s[i].pname,s[i].tat,s[i].tbt,s[i].wt,s[i].tt);
	}
	
	printf("\n\n Total Waiting Time = %d\n Average Waiting Time = %f",twt,(float)twt/n);		
	printf("\n Total TurnAround Time = %d\n Average TurnAround Time = %f\n\n",ttt,(float)ttt/n);
	printf("Exiting.. Done!\n\n");
	
}

