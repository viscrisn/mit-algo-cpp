#include <iostream>
#include <string>

using namespace std;

bool leaptest(int);
string calheader();
int days(int, int);
int weekday(int, int);

bool leapyear;

int main()
{
    int day1;
    int wkday;
  int month, year;
  cin >> month >> year;

    int day, dayofweek, leapyeartest;


    string realmonth;

    day1 =days(month, year);

    wkday= weekday(month, year);

    int startdate = 1;
    int wkd =0;

    cout<<"S\t"<<"M\t"<<"T\t"<<"W\t"
    <<"T\t"<<"F\t"<<"S"<<endl;



    for(int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++)
        {
            if(startdate>day1)
            {
                break;
            }
            if((wkd<=wkday) && (wkday!=6))
            {
                cout<<"\t";
                wkd++;
                continue;
            }
            cout<<startdate++<<"\t";
        }
        cout<<"\n";
    }
}

bool leaptest(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                leapyear = true;
            }
            else
            {
                leapyear = false;
            }
        }
        else
        {
            leapyear = true;
        }
    }
    else
    {
        leapyear = false;
    }



    return leapyear;
}

int days(int month,int year)
{
    int days;
    int month2;

    month2 = month + 11;
    month2 = month2 * 7;
    month2 = month2 % 12;

    if (month2 < 7)
        days = 31;
    else
        days = 30;

    if (month == 2)
    {
        if (leaptest(year) == true)
        {
            days = 29;
        }
        else
        {
            days = 28;
        }
    }
    return days;
}


int weekday(int month,int year)
{
    int yearedit;
    int totaldays;
    int monthedit;
    int correction;
    int daysofweek;

    yearedit = year - 1;
    totaldays = yearedit * 365;
    totaldays += (yearedit / 4);
    totaldays -= (yearedit / 100);
    totaldays += (yearedit / 400);

    if(month == 1)
        totaldays +=0;
    if(month == 2)
        totaldays +=3;
    if(month == 3)
        totaldays +=3;
    if(month == 4)
        totaldays +=6;
    if(month == 5)
        totaldays +=8;
    if(month == 6)
        totaldays +=11;
    if(month == 7)
        totaldays +=13;
    if(month == 8)
        totaldays +=16;
    if(month == 9)
        totaldays +=19;
    if(month == 10)
        totaldays +=21;
    if(month == 11)
        totaldays +=24;
    if(month == 12)
        totaldays +=26;

    if(month>2 && (leaptest(year) == true))
        totaldays +=1;

    daysofweek = totaldays % 7;
    return daysofweek;

}

