#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 50

typedef struct{
	int top;
	char items[max];
}stack;

void push(stack*s,char x);
int pop(stack*s);
int prcd (char,char);
int num(char);

int main()
{
	char v,a[max];
	int i,b=0,c;
	stack s;
	s.top=-1;
	char infx[max];
	scanf("%s",&infx);
	for(i=0;i<=strlen(infx);i++)
	{
		if((infx[i]>='0' && infx[i]<='9') || (infx[i]>='a' && infx[i]<='z') || (infx[i]>='A' && infx[i]<='Z'))
		{
			a[b++]=infx[i];
		}
		else if(infx[i]=='+'||infx[i]=='-'||infx[i]=='*'||infx[i]=='$'||infx[i]=='/')
		{
			if(s.top==-1)
			{
				push(&s,infx[i]);
			}
			else if (!(s.top==-1))
			{
				v=pop(&s);
				push(&s,v);
				if (num(v)>=num(infx[i]))
				{
					a[b++]=pop(&s);
					push(&s,infx[i]);
				}
				else
				{
					push(&s,infx[i]);
				}
			}
	}
}
	while(!(s.top==-1))
	{
	a[b++]=pop(&s);
	}
	printf("The postfix expression is %s",a);	

}
void push(stack*s,char x)
{
		s->items[++(s->top)]=x;
}
int pop(stack*s)
{
	return (s->items[(s->top)--]);
}


int num(char h)
{
if(h=='+'||h=='-')
{
	return (1);
}
else if(h=='*'||h=='/')
{
	return (2);
}
else
{
	return (3);
}

	
}

