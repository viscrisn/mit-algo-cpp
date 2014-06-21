/*Implementing stack:
    Use either Insert_front and Delete_front
                    OR
        Use Insert_rear and delete_rear

  Implementing Queues:
    Use Insert_front and delete_rear
                    OR
        insert_rear and delete_front
*/

/*This Linear Linked list program contains the following functions :
    *insert_front
    *insert_rear
    *delete_rear
    *delete_front
    *display
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
    NODEPTR first;
    first = getnode();
    first=NULL;
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
                display(first);
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
    temp->link=first;
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
        NODEPTR last;
        NODEPTR temp=getnode();
        temp->info=item;
        temp->link=NULL;

        if(first==NULL)
            return temp;

        last=first;
        while(last->link!=NULL)
        {
            last=last->link;
        }
        last->link=temp;
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
    if(first->link==NULL)
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
    prev->link=NULL;
    printf("Element deleted: %d\n",cur->info);
    free(cur);
    return first;
}












