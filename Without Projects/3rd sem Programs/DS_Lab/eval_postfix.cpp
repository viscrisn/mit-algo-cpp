#include"stack1_endsem.h"
#include<math.h>
#include<string.h>

int op(char symbol, int opnd1, int opnd2)
{
	switch(symbol)
	{
		case '+': return(opnd1+opnd2);
			   break;
		case '-': return(opnd1-opnd2);
			   break;
		case '*': return(opnd1*opnd2);
			   break;
		case '/': return(opnd1/opnd2);
			   break;

		case '^': return(pow(opnd1,opnd2));
	}
}
int isdigit(char symb)		//check symbol is digit or not
{
	if(symb>='0' && symb<='9')
		return 1;
	else
	return 0;
}



int main()
{
    int op1,op2,i,result;
	char postfix[15], symbol;
	stack s;
	s.top=-1;
    printf("enter postfix expression");
    scanf("%s",postfix);
    for(i=0;i<strlen(postfix);i++)
    {
        symbol=postfix[i];
        if(isdigit(symbol))			// call isdigit function
            push(&s,symbol-'0');
        else
        {
            op2=pop(&s);
            op1=pop(&s);
            result=op(symbol,op1,op2);	//call pop function
            push(&s,result);
        }
    }
    result =pop(&s);
    printf("result is %d",result);
}
