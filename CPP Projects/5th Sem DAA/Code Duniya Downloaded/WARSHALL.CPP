#include<iostream.h>
#include<conio.h>


void main()
{
 clrscr();
 int n,j,k,l,f=1;
 int m[10][10];
 cout<<"Enter the no. of vertices: ";
 cin>>n;

 //empty adj matrix
 for(int i=0;i<n;i++)
  for(j=0;j<n;j++)
   m[i][j]=0;
 cout<<"Enter the no. of edges: ";
 cin>>j;

 cout<<"Enter the edges: ";
 for(i=1;i<=j;i++)
 {
  cin>>k>>l;
  if(k<n && l<n)
   m[k][l]=1;
  else
   cout<<"invalid edge\n";
 }
 while(f==1)
 {
  f=0;
  for(i=0;i<n;i++)
   for(j=0;j<n;j++)
	for(k=0;k<n;k++)
	 if(m[i][j]==0 && (m[i][k]==1 && m[k][j]==1))
	 {
		  m[i][j]=1;
		  f=1;
	 }
 }
 cout<<"Transitive closure of adjacency matrix:\n";
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
   cout<<m[i][j]<<" ";
  cout<<endl;
 }
 getch();
}
