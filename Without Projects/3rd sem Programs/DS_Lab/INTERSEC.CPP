#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
typedef struct node
{
 int data;
 struct node *next;
 } ;
 typedef node *nodeptr;
 nodeptr getnode()
 {
  nodeptr p;
  p=(nodeptr) malloc(sizeof(node));
  return p;
  }
 nodeptr add(nodeptr cur, int element)
 {
 nodeptr p,ptr=cur;
 p=getnode();
 p->data=element;
 p->next=NULL;
 if (ptr==NULL)
 {
  cur=p;
  return cur;
  }
 while (ptr->next!=NULL)
 ptr=ptr->next;
 ptr->next=p;
 return cur;
 }
void display(nodeptr first)
{
 nodeptr p=first;
 printf("\nThe elements are \n");
 while (p!=NULL)
 {
  printf("%d \t", p->data);
  p=p->next;
  }
  return;
  }
nodeptr intersect ( nodeptr first, nodeptr second, nodeptr result)
{

  nodeptr one= first;
  nodeptr two=second;
   while (one!=NULL)
 {
  while (two!=NULL)
   {if (one->data==two->data){ result=add(result,one->data);break;}
   two=two->next;
   }
  one=one->next;
  two=second;
  }
   return result;
   }


main()


{
	nodeptr first=NULL;
	nodeptr second=NULL;
	nodeptr result=NULL;
	int answer,element;
//	clrscr();
	while (1)
	{
	printf("\n 1:add to list 1 \n");
	printf(" 2:add to list 2\n");
	printf(" 3:merge lists\n");
	printf(" 4:display list 1\n");
	printf(" 5:display list 2\n");
	printf(" 6: Display result \n");
	printf(" 7:exit\n");
	printf("Enter option\n");
	scanf("%d",&answer);
	switch (answer)
	{
		case 1:         printf("Enter the element\n");
				scanf ("%d",&element);
				first=add(first,element);
			break;
		case 2: 	printf("Enter the element\n");
				scanf ("%d",&element);
				second=add(second,element);
			break;
		case 3:         result= intersect(first,second,result);
			break;
		case 4:         display(first);
			break;
		case 5:         display(second);
			break;
		case 6:         display(result);
			break;
		case 7:	       exit(0);
		}  //switch

	}//while

}
