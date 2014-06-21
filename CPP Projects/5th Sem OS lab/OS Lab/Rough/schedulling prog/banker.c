#include<stdio.h>

int alloc[10][10],max[10][10],need[10][10],req[10][10];
int avail[10],work[10],finish[10],safeseq[10],r,p;


int safestate()
{	int i,j,k,x=0,l=0,flag=1;

	for(j=0;j<r;j++)
	{	work[j]=avail[j];
	}

	for(i=0;i<p;i++)
	{	finish[i]=0;
	}

	for(i=0;x<=p;i=(i+1)%p)
	{	x++;
		
		for(j=0;j<r;j++)
		{	if(need[i][j]>work[j])
			{	flag=0;
				break;
			}
		}
		if((flag==1)&&(finish[i]==0))
		{	for(j=0;j<r;j++)
			{	work[j] = work[j] + alloc[i][j];
			}
			
			finish[i]=1;
			
			x=0;
	
			printf("%d",i);
			safeseq[l]=i+1;
			l++;

		}

	}

	for(k=0;k<p;k++)
        {       if(finish[k]==0)
               	{       break;  
               	}       
        }       
        
        if(k==p)
        {	return 1;
        }    
	
	else
	{	return 0;
	}
}	

void resreq(int pi)
{	int j,ss;

	for(j=0;j<r;j++)
	{	
	 if(req[pi][j]>need[pi][j])
	 {	
	 printf("\nError :: Process %d has exceeded its maximum claim!\n",pi+1);
	 return;
	 }
	}	
	
	for(j=0;j<r;j++)
	{
	 if(req[pi][j]>avail[j])
	 {
	 printf("\nResource Allocation Denied :: Process %d must wait till resources are available\n",pi+1);
	 return;
	 }
	}

	for(j=0;j<r;j++)
	{	avail[j] = avail[j] - req[pi][j];
		alloc[pi][j] = alloc[pi][j] + req[pi][j];
		need[pi][j] = need[pi][j] - req[pi][j];
	}

	ss=safestate();

	if(ss==0)
	{	
	printf("\nAllocation Denied ; State is Unsafe :: Process %d must wait till resources are available!!\n",pi+1);
	}

	else
	{	
	printf("\nAllocation Done :: Process %d new allocation state is :\n",pi+1);
	for(j=0;j<r;j++)
	{	printf("%d \t",alloc[pi][j]);
	}
	
	}
}


void main()
{	int i,j,ss=0;

	printf("\nEnter the no. of processes : ");
	scanf("%d",&p);

	printf("Enter the no. of resources : ");
        scanf("%d",&r);

	printf("\nEnter the Allocation Matrix \n");

	for(i=0;i<p;i++)
	{	printf("Allocation for process %d ::\n",i+1);
		
		for(j=0;j<r;j++)
		{	printf("Resource %d : ",j+1);
			scanf("%d",&alloc[i][j]);
		}
	}

		
	printf("\nEnter the Max Claim Matrix :\n");

	for(i=0;i<p;i++)
	{	printf("Max Claim for process %d :\n",i+1);
		
		for(j=0;j<r;j++)
		{	printf("Resource %d : ",j+1);
			scanf("%d",&max[i][j]);
		}
	}

	
	printf("\nEnter the Available Matrix :\n");

	for(j=0;j<r;j++)
	{	printf("Resource %d : ",j+1);
		scanf("%d",&avail[j]);
	}

	
	printf("\nNeed Matrix is :\n");
	for(i=0;i<p;i++)
	{  for(j=0;j<r;j++)
	   {	need[i][j] = max[i][j] - alloc[i][j];
	   	printf("%d \t",need[i][j]);
	   }
	   printf("\n");
	}

	ss=safestate();

	if(ss==1)
	{	printf("\n\tSYSTEM IS IN SAFE STATE !!!\n");
		printf("\nSAFE SEQUENCE IS :: \n");
		
		for(i=0;i<p;i++)
		{	printf("P%d \t",safeseq[i]);
		}
		
		printf("\n\n");
	}

	else
	{	printf("\n\tSYSTEM IN UNSAFE STATE !!!\n");
		
		for(i=0;i<p;i++)
		{	safeseq[i]=0;
		}

		printf("\n\n");
	}
	
}	


