/*
COMPLETED ON 18/09/2011 BY VISHAL KRISHNA. THIS PROGRAM WORKS CORRECTLY.

TIME TAKEN TO COMPLETE THE PROGRAM ALGORITHM : 10 MINS.
TIME FOR DE-BUGGING : 55 MINS.
TIME TAKEN FOR  ADDING TEST CASES : 5 MINS.
TOTAL TIME REQUIRED TO COMPLETE THE PROGRAM : 1 HOUR 10 MINS.
TIME TAKEN TO THINK AND WRITE THIS COMMENT : 3 MINS
*/

#include<iostream>

using namespace std;

int main()
{
    int car[10], total_car;
    int current_pos,index,temp1,temp1_loc,large;
    int k;
    int test,test_store;
    cin>>test;
    test_store=test;

    int flag[test+1];

    //Enter no. of test cases
    while(test)
    {

    //enter total no of cars
    cin>>total_car;
    //enter the car order
    for(int i=0;i<10;i++)
    {
        car[i]=0;

    }
    for(int i=0;i<total_car;i++)
    {
        cin>>k;
        car[i]=k;
    }

    large=9999;
    index=0;
    current_pos=1;
    temp1=large;
    while(1)
    {
        if(car[index]==current_pos)
        {
            car[index]=-1;
            index++;
            current_pos++;
        }
        else
        {
            temp1=car[index];
            temp1_loc=index;
            index++;
        }

        if(temp1==current_pos)
        {
            temp1=large;
            car[temp1_loc]=-1;
            current_pos++;
        }

        if(car[index]>temp1)
        {
            flag[test]=-1;
            break;
        }

        if(car[index]!=current_pos && temp1!=large)
        {
            flag[test]=-1;
            break;
        }
        if(car[total_car-1]==-1)
        {
            flag[test]=1;
            break;
        }


    }
    test--;
    }
    for(int i=test_store;i>0;i--)
    {
        if(flag[i]==1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }


}
