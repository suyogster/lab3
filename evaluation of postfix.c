#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAX 100

typedef struct{
	int top;
	char items[MAX];
}stack;

void push(stack *, char);
int pop(stack *);
int dig(char),value;
int opr(char,int,int);

int main()
{
	char pstfxexp[MAX];
	int i,opnd1,opnd2,n,w;
	stack s;
	
	printf("Enter the postfix expression:\n");
	scanf("%s",pstfxexp);
	
	for(i=0;i<strlen(pstfxexp);i++)
	{
		if(dig(pstfxexp[i])==1)
		{
			push(&s,(int)(pstfxexp[i]-'0'));
		}
		
		else if(dig(pstfxexp[i])==0)
		{
			opnd2=pop(&s);
			opnd1=pop(&s);
			value=opr(pstfxexp[i],opnd1,opnd2);
			push(&s,value);
		}
		
	}
	printf("value of the given postfix operation is %d",pop(&s));
}

void push(stack *s, char x)
{
	s->items[++(s->top)]=x;
}

int pop(stack *s)
{
	return (s->items[(s->top)--]);
	
}

int dig(char symb)
{
if(symb>='0' && symb<='9')
return 1;
else
return 0;
}

int opr(char op,int a,int b)
{
	if(op=='+')
	{
		return (a+b);
	}
	else if(op=='-')
	{
		return (a-b);
	}
	else if(op=='*')
	{
		return (a*b);
	}
	else if(op=='/')
	{
		return (a/b);
	}
	else if(op=='$')
	{
		return (pow(a,b));
	}
	else{
		printf("Invalid operation!!");
		exit (0);
	}
}
