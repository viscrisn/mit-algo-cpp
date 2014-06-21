#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#define MOD 6
int COUNT=0;
class node
{
	public:
	char *s;
	node *link;
	node(char *a)  //contructor
	{
		link=NULL;
		s=new char[strlen(a)+1];
		strcpy(s,a);
		a[strlen(a)]='\0';
	}

};

node *HT[MOD];
void HTentry(char *s,int code)
{
	 node *n=new node(s);
	 node *t=HT[code];
	 if(t==NULL)	//head NULL
	 {
		 HT[code]=n;
	 //cout<<HT[code]->s<<" <- was NULL Node before in"<<code<<"\n";}
	 }
	 else      //find tail
	 {
		while(t->link!=NULL)
			t=t->link;
		t->link=n;
	 }


}

void hash(char s[])
{
	int sum=0;
	for(int i=0;s[i]!='\0';i++)
		sum+=s[i];

	HTentry(s,sum%MOD);

}
using namespace std;

int main()
{
//	clrscr();
	char input[20];
	int n;
	//NULLIFY HASH Table
	for(int j=0;j<MOD;j++)
		HT[j]=NULL;

	//Input starts here
	cout<<"Enter no of keys:";
	cin>>n;
	cout<<"Enter keys:\n";
	for(int i=0;i<n;i++)
	{
		cin>>input;
		hash(input);
	}

	//display hash table
	cout<<"Hash Table is: ";
	for(int i=0;i<MOD;i++)
	{
		node *t=HT[i];
		//getch();
		cout<<"\n"<<i<<" ->\t";
		while(t!=NULL)
		{
			cout<<t->s<<" ->\t";
			t=t->link;
		}
	}


	//Search starts here
	cout<<"\nEnter search key:";
	cin>>input;

	int sum=0;
	for(int i=0;input[i]!='\0';i++)
		sum+=input[i];
	int code=sum%MOD;

	//search hash table
	node *t=HT[code];
	for(t=HT[code]; t!=NULL; t=t->link)
	{
		COUNT++;
		if(!strcmp(t->s,input))
			{
				cout<<"Found at Hash index at:\t"<<code;
				break;
			}

	}
	cout<<endl;
	if(t==NULL) cout<<"Not Found";

	cout<<"\nNumber of comparisons:\t"<<COUNT;
	exit(0);

}
