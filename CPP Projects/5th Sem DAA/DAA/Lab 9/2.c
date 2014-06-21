#include<stdio.h>
#include<malloc.h>

void initialize (int **graph, int n);
void warshall (int **graph, int n);
void display (int **graph, int n);

int main ()
{
    int i,n;
    int **graph;
    printf("Enter the number of Verticies : ");
    scanf("%d",&n);
    graph = (int**)calloc(n,sizeof(int));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(sizeof(int)*n);
    }
    initialize(graph,n);
    warshall(graph,n);
    display(graph,n);
    return 0;
}

void initialize (int **graph, int n)
{
    int i,j;
    printf("Enter the adjacency matrix \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
}

void warshall (int **graph, int n)
{
    int i,j,k;
    for (k=0; k<n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                graph[i][j] = graph[i][j] | (graph[i][k] & graph[k][j]);
            }
        }
    }
}

void display (int **graph, int n)
{
    int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d  ",graph[i][j]);
        }
        printf("\n");
    }
}
