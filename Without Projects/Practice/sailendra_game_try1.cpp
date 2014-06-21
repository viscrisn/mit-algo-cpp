#include<iostream>
#include<conio.h>
#define SIZE 3

using namespace std;

int main()
{
    /*int a[SIZE][SIZE];
    int count=1;
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            a[i][j]=count;
            count++;
        }
    }
    a[SIZE-1][SIZE-1]=0;
*/
    /*for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<"\n\n\n";
    }*/
     //   int b[SIZE][SIZE];
    //int count=1;


    int b[SIZE][SIZE]={2,3,1,4,5,7,6,8,0};
    //int b[SIZE][SIZE]={1,2,3,4,5,6,7,0,8};
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            cout<<b[i][j]<<"\t";
        }
            cout<<"\n\n\n";
    }

    int row=SIZE-1;
    int col=SIZE-1;
    cout<<"Enter direction:\n";
    cout<<"Press n to start a new game.";
    char a;
   // cin>>a;
    while((a=getche())!='n')
    {
        //cin>>a;
        cout<<"\n";
        int chk=1;
        switch(a)
        {
            case 'w':
            if(row==0)
                chk=0;
            break;
            case 's':
            if(row==SIZE-1)
                chk=0;
            break;
            case 'a':
            if(col==0)
                chk=0;
            break;
            case 'd':
            if(col==SIZE-1)
                chk=0;
            break;
        }
        if(chk)
        {
            switch(a)
            {
                case 'w':
                int t1;
                t1=b[row][col];
                b[row][col]=b[row-1][col];
                b[row-1][col]=t1;
                row=row-1;
                break;

                case 's':
                int t2;
                t2=b[row][col];
                b[row][col]=b[row+1][col];
                b[row+1][col]=t2;
                row=row+1;
                break;

                case 'a':
                int t3;
                t3=b[row][col];
                b[row][col]=b[row][col-1];
                b[row][col-1]=t3;
                col=col-1;
                break;

                case 'd':
                int t4;
                t4=b[row][col];
                b[row][col]=b[row][col+1];
                b[row][col+1]=t4;
                col=col+1;
                break;

                default:
                cout<<"Wrong option entered!\n";

            }
            for(int i=0;i<SIZE;i++)
            {
                for(int j=0;j<SIZE;j++)
                {
                    cout<<b[i][j]<<"\t";
                }
                cout<<"\n\n\n";

            }
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

            /*int flag=0;
            int count=1;
            for(int i=0;i<SIZE;i++)
            {
                for(int j=0;j<SIZE;j++)
                {
                    if(b[i][j]!=count)
                        flag=1;
                    count++;
                    if(count==8)
                        count=0;
                }
            }
            if(flag==0)
            {
                cout<<"Congrats! You Win!!";
                break;
            }
            */
            cout<<"\n";
        }
        else
        {
            cout<<"Can't move\n";
        }
    }

}
