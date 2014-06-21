#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int arr[20];
    int rear,front;
};

void addq(queue *,int);
void deleteq(queue *);

void addq(queue * pq, int item)
{
    if(pq->rear==-1 && pq->front==0)
    {
        pq->arr[++pq->rear]=item;
    }
    else
    {
        int j;
        j=pq->rear;
        for(;j>-1;j--)
        {
            if(item<pq->arr[j])
                pq->arr[j+1]=pq->arr[j];
            else
                break;
        }
        pq->arr[j+1]=item;
        pq->rear++;

    }
}

void deleteq(queue *pq)
{
    pq->rear--;
    printf("%d\t",pq->arr[pq->front]);
    for(int i=0;i<=pq->rear;i++)
    {
        pq->arr[i]=pq->arr[i+1];
    }
}
int main()
{
    int item,n;
    queue q;
    q.rear=-1;
    q.front=0;
    for(;;)
    {
        printf("Enter choice:: 1. Add:: 2. Delete:: 3. Exit");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("Add item");
                scanf("%d",&item);
                addq(&q,item);
                break;
            case 2:
                deleteq(&q);
                break;

            case 3:
                exit(0);
            default :
                printf("Choice entered is wrong");
        }
    }
}
