#include<iostream>
#include<conio.h>
using namespace std;
#define MAX 10000
typedef struct edge{
	int cost,sourceV,destV;
}EDGE;

EDGE * prim(EDGE **,int,int);
EDGE choose(EDGE **,int *,int);
int main()
{
	int i,n,j,cost;
	char v;
	EDGE **graph,*answer;

	cout<<"Enter n: ";
	cin>>n;

	graph=new EDGE*[n];
	for(i=0;i<n;i++){
		graph[i]=new EDGE[n];
		cout<<"Adjacency for "<<(char)(i+'a')<<" (-1 for no edge):\n";
		for(j=0;j<n;j++){
			if(j==i){
				graph[i][j].cost=0;
				graph[i][j].sourceV=i;
				graph[i][j].destV=j;
				continue;
			}
			else{
				cout<<"Cost for '"<<(char)(j+'a')<<"': ";
				cin>>cost;
			}
			graph[i][j].cost=cost;
			graph[i][j].sourceV=i;
			graph[i][j].destV=j;
			if(cost==-1)
				graph[i][j].cost=MAX;
		}
	}

	cout<<"Vertex to start from: ";
	cin>>v;
	answer=prim(graph,n,v-'a');
    cost=0;
	cout<<"Starting from '"<<v<<"':\n";
	for(i=0;i<n-1;i++)
    {
        cout<<"Edge "<<(char)(answer[i].sourceV+'a')<<" - "<<(char)(answer[i].destV+'a')<<" "<<answer[i].cost<<"\n";
        cost+=answer[i].cost;
    }
    cout<<endl<<cost;
	return 0;
}

EDGE * prim(EDGE **graph,int n,int v){
	EDGE *answer=new EDGE[n-1];
	EDGE u;
	int i,j=-1;
	int *done=new int[n];

	for(i=0;i<n;i++)
		done[i]=0;
	done[v]=1;

	for(i=0;i<n-1;i++){
		u=choose(graph,done,n);
		answer[++j].cost=u.cost;
		answer[j].sourceV=u.sourceV;
		answer[j].destV=u.destV;
		done[u.destV]=1;
	}

	return answer;
}

EDGE choose(EDGE **graph,int *done,int n){
	int i,j,iMin,jMin,min=MAX;

	for(i=0;i<n;i++){
		if(done[i]==0)
			continue;
		for(j=0;j<n;j++)
			if(graph[i][j].cost!=0 && graph[i][j].cost<min && !done[j]){
				min=graph[i][j].cost;
				iMin=i;
				jMin=j;
			}
	}

	return graph[iMin][jMin];
}
