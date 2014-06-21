#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node
{
 struct node *prev;
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
 if (ptr==NULL)
 {
  cur=p;
  p->next=p->prev=p;
  return cur;
  }
  ptr=cur->prev;
 ptr->next=p;
 p->prev=ptr;
 p->next=cur;
 cur->prev=p;
 return cur;
 }
void display(nodeptr res)
{
 nodeptr p=res;
 printf("\nThe elements are \n");
 if (res==NULL) {printf("No elements in the linked list\n"); return;}
 while (p->next!=res)
 {
  printf("%d \t", p->data);
  p=p->next;
  }
  printf("%d", p->data);
  return;
  }
nodeptr linkedunion ( nodeptr first, nodeptr second, nodeptr result)
{
  nodeptr one= first;
  nodeptr two=second;
  int flag;
  if (one==NULL) {result=two; return result;}
  else if (two==NULL) {result=one; return result; }
  while (one->next!=first)
  { result=add(result,one->data);
    one=one->next;
   }
   result=add(result,one->data);
    while (two->next!=second)
    { flag=1;  one=first;
     while (one->next!=first)
      {
      if (two->data==one->data)
      {flag=0; break;}
      one=one->next;
      }
       if ((one->next ==first) && (one->data==two->data)) flag=0;
      if (flag==1)
      {result=add(result, two->data);}
      two=two->next;
   }
   while (two!=second)
   {
     flag=1; one=first;
     while (one->next!=first)
      {
      if (two->data==one->data)
      {flag=0; break;}
      one=one->next;
      }
      if ((one->next ==first) && (one->data==two->data))   return result;
      if (flag==1)
      {result=add(result, two->data);}
      two=two->next;
   }


return result;
}


main()
{
	nodeptr first=NULL;
	nodeptr second=NULL;
	nodeptr result=NULL;
	int answer,element;
	clrscr();
	while (1)
	{
	printf("\n 1:add to list 1 \n");
	printf(" 2:add to list 2\n");
	printf(" 3:display list 1\n");
	printf(" 4:display list 2\n");
	printf(" 5:union of lists \n");
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
		case 3:		display(first);
			break;
		case 4:         display(second);
			break;
		case 5:		result= linkedunion(first,second,result);
			break;
		case 6:         display(result);
			break;
		case 7:	       exit(0);
		}  //switch

	}//while

}