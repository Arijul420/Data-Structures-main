#define SIZE 50
#include<stdio.H>
#include <ctype.h>
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
char s[SIZE];
int top=-1;
int top1=-1;
int myStack[100];
void push1(int);
int pop1();
int evaluatePostfixExpression(string);
void push(char element)
{
    s[++top]=element;
}
char pop()
{
    return(s[top--]);
}
int precedence (char element)
{
    switch(element)
    {
    case '#':
        return 0;
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    }
}

int main()
{

    char infix[50],postfix[50],ch,element;
    int i=0,k=0;
    printf("Enter Infix Expression : ");
    scanf("%s",infix);
    push('#');
    while( (ch=infix[i++]) != '\0')
    {
        if( ch == '(')
            push(ch);
        else if(isalnum(ch))
            postfix[k++]=ch;
        else if( ch == ')')
        {
            while( s[top] != '(')
                postfix[k++]=pop();
            element=pop();
        }
        else
        {

            while( precedence (s[top]) >= precedence (ch) )
                postfix[k++]=pop();
            push(ch);
        }
    }
    while( s[top] != '#')
        postfix[k++]=pop();
    postfix[k]='\0';
    printf("Postfix Expression : %s\n",postfix);
    evaluatePostfixExpression(postfix);
}
int evaluatePostfixExpression(string postfix)
{
    char ch;
    int i=0,op1,op2;
    while( (ch=postfix[i++]) != '\0')
    {
        if(isdigit(ch))
            push1(ch-'0');
        else
        {
            op2=pop1();
            op1=pop1();
            switch(ch)
            {
            case '+':
                push1(op1+op2);
                break;
            case '-':
                push1(op1-op2);
                break;
            case '*':
                push1(op1*op2);
                break;
            case '/':
                push1(op1/op2);
                break;
            }
        }
    }
    printf("Evaluation Result of Postfix : %d\n",myStack[top1]);
}
void push1(int y)
{
    top1++;
    myStack[top1]=y;
}
int pop1()
{
    return myStack[top1--];
}
