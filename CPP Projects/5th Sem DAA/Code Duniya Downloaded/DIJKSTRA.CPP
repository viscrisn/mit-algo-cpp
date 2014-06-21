#include<iostream.h>
#include<conio.h>
#define MAX 10000
int choose(int *,int,int *);
void dijkstra(int,int **,int *,int,int *);
int main()
{	clrscr();
	int n,i,j,num;
	int **cost,*dist,*found;
	char v;
	cout<<"Enter n: ";
	cin>>n;
	cost=new int*[n];
	dist=new int[n];
	found=new int[n];
	for(i=0;i<n;i++){
		cost[i]=new int[n];
		for(j=0;j<n;j++){
			cost[i][j]=MAX;
			found[j]=0;
		}
	}
	for(i=0;i<n;i++){
		cout<<"Distances for '"<<(char)(i+'a')<<"' (-1 to leave blank):"<<endl;
		for(j=0;j<n;j++){
			if(j==i){
				cost[i][j]=0;
				continue;
			}
			else{
				cout<<"'"<<(char)(j+'a')<<"': ";
				cin>>num;
			}
			if(num!=-1)
				cost[i][j]=num;
		}
	}
	cout<<"\n\nVertex: ";
	cin>>v;
	dijkstra(v-'a',cost,dist,n,found);
	for(i=0;i<n;i++)
		cout<<(char)('a'+i)<<"\t";
	cout<<endl;
	for(i=0;i<n;i++)
		cout<<dist[i]<<"\t";
	cout<<endl;
	getch();
	return 0;
}
int choose(int *dist,int n,int *found){
	int i,min=MAX,minPos=-1;

	for(i=0;i<n;i++){
		if(dist[i]<min && !found[i]){
			min=dist[i];
			minPos=i;
		}
	}
	return minPos;
}
void dijkstra(int v,int **cost,int *dist,int n,int *found){
	int i,u,w;
	for(i=0;i<n;i++){
		found[i]=0;
		dist[i]=cost[v][i];
	}
	found[v]=1;
	dist[v]=0;
	for(i=0;i<n-2;i++){
		u=choose(dist,n,found);
		found[u]=1;
		for(w=0;w<n;w++)
			if(!found[w] && dist[w]>(dist[u]+cost[u][w]))
				dist[w]=dist[u]+cost[u][w];
	}
}