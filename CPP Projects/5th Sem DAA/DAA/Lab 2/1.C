#include<stdio.h>
#include<conio.h>
#include<math.h>

int prm_arr[10000];

void seive(int n)
{
	int arr[10000],p,j,i;
	for(p=2;p<=n;p++)
	{
		arr[p]=p;
	}
	for(p=2;p<=sqrt(n+1);p++)
	{
		if(arr[p]!=0)
		{
			j=p*p;
		}
		while(j<=n+1)
		{
			arr[j]=0;
			j=j+p;
		}
	}
	i=0;
	for(p=2;p<=n+1;p++)
	{
		if(arr[p]!=0)
		{
			prm_arr[i]=arr[p];
			i++;
		}
	}
}

int euclid(int m,int n)
{
	if(n==0)
		return m;
	return euclid(n,m%n);
}

int cic(int x,int y)
{
	int t;
	t=x<y?x:y;
	while(t>0)
	{
		if(x%t==0)
		{
			if(y%t==0)
			{
				return t;
			}
		}
		t--;
	}
	return 1;
}

int prime(int num)
{
	int i;
	for(i=0;i<=10000;i++)
	{
		if(prm_arr[i]==num)
			return 1;
	}
	return 0;
}

int msp(int x,int y)
{
	int i,j,gcd,m,n;
	m=x;
	n=y;
	gcd=1;
	i=j=2;
	while(i<=x && j<=y)
	{
		if(m%i==0 && n%j==0 && prime(i)==1 && prime(j)==1 && i==j)
		{
			gcd*=i;
			m/=i;
			n/=j;
		}
		else
		{
			i++;
			j++;
		}
	}
	return gcd;
}

void main()
{
	int a,b,gcd,ch;
	clrscr();
	printf("\nEnter two nos. :- ");
	scanf("%d %d",&a,&b);
	printf("\tMENU\n1) GCD using Euclid's Algorithm\n2) GCD using Consecutive Integer Checking Algorithm\n3) GCD using Middle School Algorithm\n4) Exit");
	while(1)
	{
		printf("\nEnter choice :- ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	gcd=euclid(a,b);
				printf("GCD = %d",gcd);
				break;
			case 2:	gcd=cic(a,b);
				printf("GCD = %d",gcd);
				break;
			case 3:	seive(10000);
				gcd=msp(a,b);
				printf("GCD = %d",gcd);
				break;
			case 4:	exit(0);
		}
	}
}