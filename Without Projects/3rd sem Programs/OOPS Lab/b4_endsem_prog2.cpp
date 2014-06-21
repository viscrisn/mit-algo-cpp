#include<iostream>
#include<cstring>

using namespace std;
class String
{
        char *ch;
    public:
        String();
        String(char []);
        String(const String&);
        String operator+(String);
        void display();
        void changecase();
        ~String();
};

String::String()
{
    ch=NULL;
}
String::String(char s[])
{
    ch=new char[strlen(s)+1];
    strcpy(ch,s);
}
String::String(const String& ss)
{
    ch = new char[strlen(ss.ch)+1];
    strcpy(this->ch,ss.ch);
}
String String::operator+(String a)
{
    String temp;
    strcat(ch,a.ch);
    strcpy(temp.ch,ch);
    return temp;
}

void String::display()
{
    if(ch!=NULL)
        cout<<"\nThe String is:\t"<<ch;
    else
        cout<<"Empty string\n";
}

void String::changecase()
{
    for(int i=0;i<strlen(ch);i++)
    {
        if(isupper(ch[i]))
        {
            ch[i]=tolower(ch[i]);
        }
        else
            ch[i]=toupper(ch[i]);
    }
}

String::~String()
{
    if(!ch)
    {
        delete [] ch;
        ch=NULL;
    }
}

int main()
{
    char s[20];
    cout<<"Enter string";

    cin>>s;

    String s1(s);
    s1.display();
    s1.changecase();
    s1.display();

    String s2(s1);
    s2.display();

    String s3=s1+s2;
    s3.display();
}
