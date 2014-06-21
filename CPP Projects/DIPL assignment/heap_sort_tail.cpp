
#include<stdio.h>
#include<conio.h>

int hsort[25],n,i;

void adjust(int,int);
void heapify();
void heap_sort();

int main()
{
    heap_sort();
}

void heap_sort()
{
    int temp;
    printf("\n\t\t\t\tHEAP SORT");
    printf("\n\t\t\t\t**** ****\n\n\n");
    printf("\nenter no of elements:");
    scanf("%d",&n);
    printf("\nenter elements to be sorted\n\n");

    for(i=1; i<=n; i++)
        scanf("%d",&hsort[i]);
    heapify();

    for(i=n; i>=2; i--)
    {
        temp=hsort[1];
        hsort[1]=hsort[i];
        hsort[i]=temp;
        adjust(1,i-1);
    }

    printf("\nSORTED ELEMENT\n\n");
    for(i=1; i<=n; i++)
        printf("%d\n",hsort[i]);
}

void heapify()
{
    int i;
    for(i=n/2; i>=1; i--)
        adjust(i,n);
}
void adjust(int i,int n)
{
    int j,element;
    j=2*i;
    element=hsort[i];
    while(j<=n)
    {
        if((j<n)&&(hsort[j]<hsort[j+1]))
            j=j++;
        if(element>=hsort[j])
            break;
        hsort[j/2]=hsort[j];
        j=2*j;
    }
    hsort[j/2]=element;
}


