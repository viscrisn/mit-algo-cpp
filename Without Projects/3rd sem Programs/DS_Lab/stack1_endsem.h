#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct stack
{
    int top;
    int arr[SIZE];
};

void push(stack *,int);
int pop(stack *);
void display(stack);

void push(stack *s,int item)
{
    if(s->top==SIZE)
    {
        printf("Stack Is full\n");
        return;
    }
    s->arr[++s->top]=item;
}

int pop(stack *s)
{
    if(s->top==-1)
    {
        printf("Stack is Empty\n");
        return NULL;
    }
    return (s->arr[s->top--]);
}

void display(stack s)
{
    if(s.top==-1)
    {
        printf("Stack is Empty\n");
    }
    for(int i=s.top;i>-1;i--)
    {
        printf("%d\t",s.arr[i]);
    }
}




