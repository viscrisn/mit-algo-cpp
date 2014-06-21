#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

struct process 
{
int processid;
int waittime;
int bursttime;
int arrivaltime;
int turnaroundtime;
};

void main()
{
int n,i,x,y,z,k,j,tempwait,tempturnaround,wt=0,tt=0;
struct process proc[50],temp;
printf("\n enter no.of process : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\n enter process id : ");
scanf("%d",&proc[i].processid);
printf("\n enter burst time : ");
scanf("%d",&proc[i].bursttime);
printf("\n enter arrival time : ");
scanf("%d",&proc[i].arrivaltime);
}
for(j=0;j<n;j++)
for(k=0;k<n-1-j;k++)
{
if(proc[k].arrivaltime>proc[k+1].arrivaltime)
{
temp=proc[k];
proc[k]=proc[k+1];
proc[k+1]=temp;

}
}

for(z=0;z<n;z++)
{
proc[z].waittime=wt-proc[z].arrivaltime;
wt=wt+proc[z].bursttime;
}
for(y=0;y<n;y++)
{
tt=tt+proc[y].bursttime;
proc[y].turnaroundtime=tt-proc[y].arrivaltime;
}
for(x=0;x<n;x++)
{
printf("processID : %d\n",proc[x].processid);
printf("arrivaltime : %d\n",proc[x].arrivaltime);
printf("burst time : %d\n",proc[x].bursttime);
printf("wait time : %d\n",proc[x].waittime);
printf("turn around time : %d\n",proc[x].turnaroundtime);
}}
