//#include<process.h>
#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
using namespace std;

void push(int b[],int *t,int item)
{
    if(*t==SIZE-1)
    {
        printf("Stack full");
        return;

    }
    *t=*t+1;
    b[*t]=item;
}

int pop(int s[],int *t)
{
    int item;
    if(*t==-1)
    {
        printf("Stack EMpty");
        return -1;
    }

    item=s[*t];
    *t=*t-1;
    return(item);
}

void display(int s[],int top)
{
    if(top==-1)
    {
        printf("Stack is empty");
        return;
    }

    for(int i=0;i<=top;i++)
    {
        printf("%d\t",s[i]);
    }
}

int main()
{
    int a[SIZE];
    int top=-1;
    int choice,item;

    printf("1: Push, 2: Pop, 3: Display, 4: Exit");

    do
    {
        printf("Enter Choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter item\n");
                scanf("%d",&item);
                push(a,&top,item);
                break;

            case 2:
                printf("Deleted itme %d\n",pop(a,&top));
                break;

            case 3:
                display(a,top);
                break;
            case 4:
                exit(0);
        }
    }
    while(choice!=4);
}

