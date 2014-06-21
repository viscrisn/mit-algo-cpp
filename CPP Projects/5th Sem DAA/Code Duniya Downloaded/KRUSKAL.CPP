#include<iostream.h>
#include<conio.h>
#define MAX 2001
int count = 0;
int ecount = 0;
int tree = 0;

int present( int V[][2], int ver )
{
	for( int i = 0; i<count; i++ )
	{
		if( V[i][0] == ver ) return 1;
	}
	return 0;
}

int rettree( int V[][2], int ver )
{
	for( int i = 0; i<count; i++ )
		if( V[i][0] == ver ) return V[i][1];
	return 0;
}

void ADDEDGE( int ver1, int ver2, int E[][2] )
{
	int flag = 0;
	for( int i = 0; i<ecount; i++ )
	{
		if( E[i][0] == ver1 && E[i][1] == ver2 )
			flag = 1;
	}
	if( flag == 0 )
	       {	E[ecount][0] = ver1; E[ecount][1] = ver2;
			ecount++;
	       }
}

int ADDVERT( int v1, int v2, int V[][2] )
{
	if( present( V, v1+1 ) && present( V, v2+1 ) )
	{
		if( rettree( V, v1+1 ) != rettree( V, v2+1 ) )
		{
			int t1 = rettree( V, v1+1 );
			int t2 = rettree( V, v2+1 );
			for( int i = 0; i<count; i++ )
			{
				if( V[i][1] == t1 )
					V[i][1] = tree;
				if( V[i][1] == t2 )
					V[i][1] = tree;
			}
			tree++;
			return 1;
		}
		else return 0;
	}
	else if( present( V, v1+1 ) )
	{
		int t = rettree( V, v1+1 );
		for( int i = 0; i<count; i++ )
		{
			if( V[i][1] == t )
				V[i][1] = tree;
		}
		V[count][0] = v2+1; V[count++][1] = tree;
		tree++;
		return 1;
	}
	else if( present( V, v2+1 ) )
	{
		int t = rettree( V, v2+1 );
		for( int i = 0; i<count; i++ )
		{
			if( V[i][1] == t )
				V[i][1] = tree;
		}
		V[count][0] = v1+1; V[count++][1] = tree;
		tree++;
		return 1;
	}
	else
	{
		V[count][0] = v1+1; V[count++][1] = tree;
		V[count][0] = v2+1; V[count++][1] = tree;
		tree++;
		return 1;
	}
}

void Kruskal( int D[][10], int v, int V[][2], int E[][2] )
{
	int min = D[0][0], v1 = 0, v2 = 0;
	while( count < v )
	{
	min = 2000; v1 = 0; v2 = 0;
	for( int i = 0; i < v; i++ ) //find minimum in the distance matrix
	{
		for( int j = i+1; j < v; j++ )
		{
			if( D[i][j] < min )
			{
				min = D[i][j];
				v1 = i; v2 = j;
			}
		}
	}
	D[v1][v2] = D[v2][v1] = MAX;
	if( ADDVERT( v1, v2, V ) == 1 )
	{
		ADDEDGE( v1+1, v2+1, E );
	}
	//else cout<<"\nEdge not added";
}
}
void main()
{
	clrscr();
	int D[10][10], E[10][2], V[10][2], v;
	cout<<"Input the number of vertices(<10): ";
	cin>>v;
	cout<<"Input the distance matrix (Press -1 if no path): ";
	for( int i = 0; i<v; i++ )
	{	for( int j =i+1; j<v; j++ )
		{       cout<<i+1<<" "<<j+1<<": ";
			cin>>D[i][j];
			if( D[i][j] == -1 ) D[i][j] = MAX;
		}
	}
	Kruskal( D, v, V, E );
	cout<<"The vertices are: ";
	for( i= 0; i<v; i++ )
		cout<<V[i][0]<<" ";
	cout<<"\nThe edges are:\n";
	for( i = 0; i<(v-1); i++ )
	{
		cout<<E[i][0]<<" "<<E[i][1]<<"\n";
	}
	getch();
}