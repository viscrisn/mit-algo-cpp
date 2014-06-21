/*
                CIRCULAR LINKED LIST WITH firstER NODE
*/

/*This linked list program contains the following functions :
    *insert_front
    *insert_rear
    *delete_rear
    *delete_front
    *display
    *Merging
*/

#include<process.h>
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node* link;
};

typedef node* NODEPTR;


NODEPTR getnode();
NODEPTR delete_front(NODEPTR);
NODEPTR insert_front(int,NODEPTR);
void display(NODEPTR);
NODEPTR insert_rear(int, NODEPTR);
NODEPTR delete_rear(NODEPTR);


int main()
{
    NODEPTR first = NULL;
    int choice;
    int item;
    printf("1: Insert front 2: Insert rear 3: Delete Front 4: Delete Rear ");
    printf("\n5: Display 6: Exit");
    while(1)
    {
        printf("Enter choice: \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter item: ");
                scanf("%d",&item);
                first=insert_front(item,first);
                break;

            case 2:
                printf("Enter item: ");
                scanf("%d",&item);
                first=insert_rear(item,first);
                break;

            case 3:
                first = delete_front(first);
                break;

            case 4:
                first = delete_rear(first);
                break;

            case 5:
                display(first->link);
                break;

            case 6:
                exit(0);
                break;

            default:
                printf("Wrong choice entered!!\n");

        }
    }



}

NODEPTR getnode()
{
    NODEPTR temp;
    temp=(NODEPTR)malloc(sizeof(struct node));
    temp->link=NULL;
    return temp;
}

NODEPTR insert_front(int item, NODEPTR first)
{
    NODEPTR temp=getnode();
    temp->info=item;
    if(first!=NULL)
    {
        temp->link=first;
    }
    else
    {
        temp->link=temp;
    }
    NODEPTR cur=first;
    //Making it circular
    while(cur->link!=cur)
    {
        cur=cur->link;
    }
    cur->link=temp;
    //Made it
    return temp;

}

NODEPTR delete_front(NODEPTR first)
{
    NODEPTR temp=first;
    if(first==NULL)
        {
            printf("Empty list\n");
            return NULL;
        }
    else
    {
        printf("Deleted item: %d\n",first->info);
        temp=first->link;

    //Making it circular
        NODEPTR cur=first;
        while(cur->link!=cur)
        {
            cur=cur->link;
        }
        cur->link=temp;
    //Made it
        free(first);
        return temp;
    }

}

void display(NODEPTR first)
{
    NODEPTR temp=first;
    if(temp==NULL)
    {
        printf("List Empty!\n");
    }
    while(temp!=NULL)
    {
        printf("%d\n",temp->info);
        temp=temp->link;
    }
}

NODEPTR insert_rear(int item, NODEPTR first)
{
        NODEPTR last=first;
        NODEPTR temp=getnode();
        temp->info=item;
        temp->link=NULL;

        if(first==NULL)
            return temp;

        while(last->link!=NULL)
        {
            last=last->link;
        }
        last->link=temp;
        //Making it circular
        temp->link=first;
        //Made it
        return first;
}

NODEPTR delete_rear(NODEPTR first)
{
    NODEPTR prev;
    NODEPTR cur=first;
    if(first==NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    if(first->link==first)
    {
        printf("Element deleted: %d\n",first->info);
        free(first);
        return NULL;
    }
    while(cur->link!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    prev->link=first;
    printf("Element deleted: %d\n",cur->info);
    free(cur);
    return first;
}












