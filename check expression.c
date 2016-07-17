#include <stdio.h>
#include <string.h>
#include <conio.h> 
#define max 50

typedef struct{
	int top;
	int items[max];
	}stack;

char check(char);
void push(stack*s,int x);
int pop(stack*s);

int main()
{
	char exp[100],a,k;
	int i,valid=1;
	stack s;		
	s.top=-1;	
	printf("\nEnter an expression ");
	scanf("%s",exp);
	for(i=0; i<=strlen(exp);i++)
		{
		if( exp[i]=='(' || exp[i] =='[' || exp[i] == '{' )
		{
			push(&s,exp[i]);

		}
		if ( exp[i]==')' || exp[i] ==']' || exp[i] == '}' )
		{
			if(s.top==-1)
			{
				valid=0;
			}
			else{
			k=check(exp[i]);	
			a=pop(&s);
			if(a!=k)
			{
				valid=0;
				break;
			}
		}
		}
	}
	if (!(s.top==-1))
	{
		valid=0;
	}
			
			if(valid==1)
			{
				printf("The expression is valid");
			}
			else
			{
				printf("The expression is invalid");
			}

}
void push(stack*s,int x)
{

		s->items[++(s->top)]=x;
}
int pop(stack*s)
{
	return (s->items[(s->top)--]);
}
char check(char a)
{
	if(a==')')
	{
		return '(';
	}
	if (a=='}')
	{
		return '{';
	}
	if (a==']')
	{
		return '[';
	}
}
