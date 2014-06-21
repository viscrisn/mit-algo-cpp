#include<iostream>
#include<string.h>

using namespace std;

class movie
{
    char title[30];
    char director[30];
    int year;

    public:
        void settitle(char []);
        void setyear(int);
        void setdirector(char []);
        void display();
        int chk(movie);
};

void movie::settitle(char a[30])
{
    strcpy(title,a);
}

void movie::setdirector(char a[30])
{
    strcpy(director,a);
}

void movie::setyear(int a)
{
    year=a;
}
 void movie::display()
 {
     cout<<"\nTitle : Year : Director\n"
     <<title<<"\t"<<year<<"\t"<<director<<"\n";
 }

 int movie::chk(movie m1)
 {
     if(m1.year==year)
     {
         if(strcmp(m1.director,director))
         {
             return 1;
         }
         else
            return 2;
    }
    else
    {
         if(strcmp(m1.director,director))
         {
             return 3;
         }
         else
            return 4;
    }

}

int main()
{
    int year;
    char ttle[30],drctor[30];
    char *title=ttle;
    char *director=drctor;
    movie A,B;
    cout<<"Enter the title, year, director for movie 1\n";
    cin>>title>>year>>director;
    A.settitle(title);
    A.setdirector(director);
    A.setyear(year);

    cout<<"Enter the title, year, director for movie 2\n";
    cin>>title>>year>>director;
    B.settitle(title);
    B.setdirector(director);
    B.setyear(year);

    A.display();
    B.display();

    int checker;
    checker = B.chk(A);

    if(checker==2)
        cout<<"\nSame year, Same director";
    if(checker==1)
        cout<<"\nSame year, Different director";
    if(checker==4)
        cout<<"\nDifferent year, Same director";
    if(checker==3)
        cout<<"\nDifferent year, Different director";
}






















