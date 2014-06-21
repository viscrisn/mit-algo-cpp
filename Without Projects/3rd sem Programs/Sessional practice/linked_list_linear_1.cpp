#include<stdio.h>
#include<stdlib.h>
#include<process.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};

typedef node* NODEPTR;

NODEPTR getnode()
{
    NODEPTR x=NULL;
    x=(NODEPTR)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Not enough memory");
        exit(0);
    }
    return x;
}

NODEPTR insert_front(int item,NODEPTR head)
{
    NODEPTR temp=getnode();
    temp->info=item;
    if(head->rlink==head)
    {
        temp->llink=head;
        temp->rlink=head;
        head->rlink=temp;
        head->llink=temp;
        return head;
    }
    NODEPTR cur=head->rlink;
    head->rlink=temp;
    temp->llink=head;
    temp->rlink=cur;
    cur->llink=temp;
    return head;
}

void display(NODEPTR head)
{
    if(head->rlink==head)
    {
        printf("List is empty");
    }
    else
    {
        NODEPTR cur=head->rlink;
        while(cur!=head)
        {
            printf("%d\t",cur->info);
            cur=cur->rlink;
        }
    }
    return;
}

NODEPTR delete_last(NODEPTR head)
{
    if(head->rlink==head)
    {
        printf("The list is empty");
        return head;
    }
    NODEPTR cur,prev;
    cur=head->rlink;
    prev=cur;
    if(cur->rlink==head)
    {
        printf("Deleted node is: %d",cur->info);
        head->rlink=head;
        free(cur);
        cur=NULL;
        return head;
    }
    while(cur->rlink->rlink!=head)
    {
        cur=cur->rlink;
        prev=cur;
    }
    cur=cur->rlink;
    printf("Deleted node is: %d\n",cur->info);
    cur=NULL;
    free(cur);

    prev->rlink=head;
    head->llink=prev;
    return head;

}

int main()
{
    NODEPTR head=getnode();
    head->llink=head;
    head->rlink=head;
    head->info=0;

    int item,choice;
    while(1)
    {
        printf("Enter 1: Add front \n2: Display \n3: Delete last\n4: Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element:\n");
                scanf("%d",&item);
                head=insert_front(item,head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                head=delete_last(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice, Enter again\n");
                break;

        }
    }

}
