#include "linked_list.h"

void sort(NODEPTR head)
{
    int t;
    NODEPTR temp;
    for(NODEPTR i=head->rlink;i!=head;i=i->rlink)
    {
        for(NODEPTR j=head->rlink;j!=i;j=j->rlink)
        {
            if(i->info<j->info)
            {
                t=i->info;
                i->info=j->info;
                j->info=t;
            }
        }
    }
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
        printf("Enter 1: Add front \n2: Display \n3: Delete last\n4: Sort the list\n5: Exit\n");
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
                sort(head);
                printf("The list is now sorted\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong choice, Enter again\n");
                break;

        }
    }

}

