#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int **allocation;
int **max;
int **need;
int *available;
int n,m;


void input()
{
  int i,j;
  allocation=(int **)malloc(sizeof(int *) *n);
  max=(int **)malloc(sizeof(int *) *n);
  need=(int **)malloc(sizeof(int *) *n);
  for(i=0;i<n;i++)
  {
    allocation[i]=(int *)malloc(sizeof(int)*m);
    max[i]=(int *)malloc(sizeof(int)*m);
    need[i]=(int *)malloc(sizeof(int)*m);
  }

 available=(int *)malloc(sizeof(int)*m);

  printf("Enter allocation matrix :\n");
  for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	  scanf("%d",&allocation[i][j]);

  printf("Enter max matrix :\n");
  for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	  scanf("%d",&max[i][j]);

  printf("Enter available array :\n");
  for(j=0;j<m;j++)
	scanf("%d",&available[j]);

}


void calcNeed()
{
  int i,j;
  need=(int **)malloc(sizeof(int *) *n);
  for(i=0;i<n;i++)
    need[i]=(int *)malloc(sizeof(int)*m);
  printf("Need : \n");
  for(i=0;i<n;i++)
  {
	for(j=0;j<m;j++)
 	{
	  need[i][j]=max[i][j]-allocation[i][j];
	  printf("%d ",need[i][j]);
	}
	printf("\n");
  }
}

bool isSafe()
{
  int *work,*safeSequence;
  int i,j,k=0,count=1,temp;
  bool *finish;
  bool flag;
  work=(int *)malloc(sizeof(int)*m);
  safeSequence=(int *)malloc(sizeof(int)*n);
  finish=(bool *)malloc(sizeof(bool)*n);

  for(i=0;i<m;i++)
 	work[i]=available[i];
  for(i=0;i<n;i++)
	finish[i]=false;

  while(count<=n)
  {
	for(i=0;i<n;i++)
	{
	  flag=true;
	  printf("\ni=%d ",i);

	  if(finish[i]==false)
	  {

	  printf("Need : ");
  	  for(temp=0;temp<m;temp++)
	    printf("%d ",need[i][temp]);
	  printf("Work : ");
	  for(temp=0;temp<m;temp++)
	    printf("%d ",work[temp]);


	    for(j=0;j<m;j++)
		  if(need[i][j]>work[j])
		    flag=false;

        if(flag)
	    {
		  for(j=0;j<m;j++)
		    work[j]+=allocation[i][j];
		  printf("\tFinish[%d]=true",i);
		  finish[i]=true;
		  safeSequence[k++]=i;
	    }

  	  }
    }
    count++;
  }

  flag=true;
  for(i=0;i<n;i++)
  {
	if(finish[i]==false)
	{
	  flag=false;
	  break;
	}
  }

  if(flag)
  {
    printf("\n\nSafe sequence : ");
	for(i=0;i<n;i++)
	  printf("%d ",safeSequence[i]);

    return true;
  }
  else
  {
    printf("\n\nSystem not in safe state");
    return false;
  }
}

int main()
{
  int *request,i,j;
  bool safe,validRequest=true;
  printf("Enter no. of processes and no. of resources : ");
    scanf("%d %d",&n,&m);
  input();
  calcNeed();
  safe=isSafe();

  request=(int *)malloc(sizeof(int)*m);
  printf("\n\nEnter id of requesting process : ");
    scanf("%d",&i);
  printf("Enter request array : ");
  for(j=0;j<m;j++)
    scanf("%d",&request[j]);


  for(j=0;j<m;j++)
  {
    if(request[j]>need[i][j] || request[j]>available[j])
      validRequest=false;
  }


  if(validRequest)
  {
    for(j=0;j<m;j++)
    {
      available[j]=available[j]-request[j];
      allocation[i][j]=allocation[i][j]+request[j];
      need[i][j]=need[i][j]-request[j];
    }
  }

  

  safe=isSafe();
  if(!safe)
  {
    available[j]=available[j]+request[j];
    allocation[i][j]=allocation[i][j]-request[j];
    need[i][j]=need[i][j]+request[j];
  }

  printf("\n");
  return 0;
}
