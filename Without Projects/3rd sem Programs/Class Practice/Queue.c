#include<stdio.h>
#include<process.h>
#define SIZEQ 5
typedef struct
{
    int f;
    int r;
    int a[SIZEQ];
}QUEUE;

int addq(QUEUE *q,int item);
int deleteq(QUEUE *q);
void display(QUEUE q);

int main()
{
    int item,n;
    QUEUE q;
    q.r=-1;
    q.f=0;
    for(;;)
    {
        printf("Enter choice:: 1. Add:: 2. Delete:: 3. Display:: 4. Exit");
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
                display(q);
                break;
            case 4:
                exit(0);
            default :
                printf("Choice entered is wrong");
        }
    }
}

int addq(QUEUE *q,int item)
{
    if(q->r>=SIZEQ-1)
    {
        printf("Queue Full, Cant add %d\n",item);
        return -1;
    }
    else
    {
        (q->r)++;
        q->a[q->r]=item;

    }
}

int deleteq(QUEUE *q)
{
    if(q->f>q->r)
    {
        printf("Queue Empty\n");
        return -1;
    }
    else
    {
        printf("%d",q->a[q->f]);
        (q->f)++;
        return q->a[q->f];
    }
}

void display(QUEUE q)
{
    int i;
    if(q.f>q.r)
    {
        printf("Queue Empty\n");
    }
    else
        for(i=q.f;i<=(q.r);i++)
        {
            printf("%d",q.a[i]);
        }
}






