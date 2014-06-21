#include"stack1_endsem.h"

int main()
{
    stack s;
    s.top=-1;
    int choice,item;
    do
    {
        printf("1: Push, 2: Pop, 3: Display, 4: Exit");
        printf("Enter Choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter item\n");
                scanf("%d",&item);
                push(&s,item);
                break;

            case 2:
                printf("Deleted itme %d\n",pop(&s));
                break;

            case 3:
                display(s);
                break;

            case 4:
                exit(0);

            default:
                printf("Wrong choice!\n");

        }
    }
    while(choice!=4);
}
