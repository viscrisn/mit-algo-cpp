//round robin

#include<stdio.h>

struct process
{
  int pid;
  int atime;
  int wtime;
  int left;
  int btime;
  int ttime;
  int finish;
}pro[5];

int i=0;

int finish()
{
  int j;
  for(j=0;j<i;j++)
  {
    if(pro[j].finish==0)
    {
      return 0;
    }
  }
  return 1;
}


int main()
{
  

  char chart[100];
  char symbol[5]={'1','2','3','4','5'};
  int choice=1;
  float awtime=0,attime=0;
  do
  {
    printf("\nDo you have a process?(1/0)");
    scanf("%d",&choice);
    if(choice==1)
    {
      printf("\nProcess id:");
      scanf("%d",&pro[i].pid);
      printf("\nArrival time:");
      scanf("%d",&pro[i].atime);
      printf("\nBurst time:");
      scanf("%d",&pro[i].btime);
      pro[i].left=pro[i].btime;
      pro[i].finish=0;

      i++;
    }
  }while(choice==1);

  int tslice=4;
  int s=0;
  int flag;
  int totaltime=0;
  int j,c,d;

  do
  {
    flag=1;
    for(j=0;j<i;j++)
    {

      if((pro[j].atime<=totaltime)&&(pro[j].finish==0))
      {
	   flag=0;
	   if(pro[j].left>tslice)
	   {
	     pro[j].left=pro[j].left-tslice;
	     totaltime+=tslice;
	     for(d=0;d<tslice;d++)
	     {
	       chart[s]=symbol[j];
	       s++;
	     }
	   }//end of if 2
	   else
	   {

	     totaltime+=pro[j].left;
	     pro[j].finish=1;
	     pro[j].wtime=totaltime-pro[j].atime-pro[j].btime;
	     pro[j].ttime=totaltime-pro[j].atime;
	      for(d=0;d<pro[j].left;d++)
	      {
		chart[s++]=symbol[j];
	      }
	     pro[j].left=0;
	   }
      }
    }//end of for
    if(flag==1)
    {
      c=finish();
      if(c!=1)
      {
	totaltime++;
	chart[s++]='i';
      }
    }
  }while(c!=1);

 //chart[s]='\0';
 //printf("%schart<<"\n";
 printf("\nPID\tWtime\tTTime\n");
  for( j=0;j<i;j++)
  {
   printf("\n%d  \t    %d    \t    %d ",pro[j].pid,pro[j].wtime,pro[j].ttime);
  }
  for(j=0;j<i;j++)
  {

  awtime+=pro[j].wtime;
  attime+=pro[j].ttime;
  }
  printf("\nAverage waiting time:%f",awtime/i);
  printf("\nAverage turnaround time:%f",attime/i);
 
}
