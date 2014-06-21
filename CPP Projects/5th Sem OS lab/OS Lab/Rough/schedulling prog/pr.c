#include<stdio.h>
#include<stdlib.h>


struct proc{
	int at;
	int wt;
	int bt;
	int tt;
	int p;
	int flag;
	char pname[20];
}s[10],temp;

void main(){

	int n,i,j;
	printf("\n\n Priority Scheduling : Non Pre-Emptive ");
	printf("\n\n Enter Number of Processes : ");
	scanf("%d",&n);
	printf("\n Enter Details : ");
	for(i=0;i<n;i++){
		printf("\n   Process Name - ");
		scanf("%s",s[i].pname);
		printf("\n   Process Arrival time - ");
		scanf("%d",&s[i].at);
                printf("\n   Process Burst time - ");
                scanf("%d",&s[i].bt);
		printf("\n   Process Priority - ");
                scanf("%d",&s[i].p);
		s[i].flag=0;
	}

	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(s[j].at>s[j+1].at){
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
	
	int active;
	int time=0;
	int k=0,least,twt=0,ttt=0;
	while(k<10){
		for(i=0;i<n;i++){
			if(s[i].flag==1){	continue;	}
			while(s[i].at>time){	time++;		}
			least=i;
			for(j=0;j<n;j++){
				if(s[j].at<=time&& s[j].flag==0){
					if(s[j].p<s[least].p)	least=j;
				}
			}
			s[least].wt=time-s[least].at;
			twt+=s[least].wt;
			s[least].tt=s[least].wt+s[least].bt;
			time+=s[least].bt;
			ttt+=s[least].tt;
			s[least].flag=1;
		}
	k++;	
	}


	printf("\n\n\nP Name\tArv Time\tBurst Time\tWaiting Time\tTurn A. Time");
	printf("\n------\t--------\t----------\t------------\t------------\n");

	for(i=0;i<n;i++){
		printf("\n%s  \t    %d    \t    %d     \t     %d      \t     %d      ",s[i].pname,s[i].at,s[i].bt,s[i].wt,s[i].tt);
	}
	
	printf("\n\n Total Waiting Time = %d\n Average Waiting Time = %f",twt,(float)twt/n);		
	printf("\n Total TurnAround Time = %d\n Average TurnAround Time = %f\n\n",ttt,(float)ttt/n);
	printf("Exiting.. Done!\n\n");
	
}

