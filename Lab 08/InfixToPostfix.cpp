#include <bits/stdc++.h>
using namespace std;
char a[100],s[100],c;
int temp;

struct Node
{
    char data;
    int data2;
    struct Node* next;
};
struct Node* top=NULL;

void push(int choice)
{
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    if(choice==1)
        newNode->data=c;
    else if(choice==2)
        newNode->data2=temp;
    if(top==NULL)
        newNode->next=NULL;
    else
        newNode->next=top;
    top=newNode;
}

void pop(){
    if(top==NULL)
        return;
    else{
        struct Node *temp=top;
        top=temp->next;
        free(temp);
    }
}

char Top(int choice){
    if(choice==1)
        return top->data;
    return top->data2;
}

int isEmpty(){
    return top==NULL;
}

int isNum(char ch){
    return ch>='0' && ch<='9';
}

int prec(char ch){
    int n=-1;
    if(ch=='^')
        n=3;
    else if(ch=='*' || ch=='/')
        n=2;
    else if(ch=='+' || ch=='-')
        n=1;
    return n;
}

void getpostfix(){
    int i,j=0;
    for(i=0;i<strlen(a);i++)
    {
        if(isNum(a[i]))
        {
            while(isNum(a[i]) && i<strlen(a))
                s[j++]=a[i++];
            i--;
            s[j++]=' ';
        }
        else if(a[i]=='('){
            c='(';
            push(1);
        }
        else if(a[i]==')'){
            while(!isEmpty() && Top(1)!='(')
            {
                s[j++]=Top(1);
                pop();
            }
            if(Top(1)=='(')
                pop();
        }
        else{
            while(!isEmpty() && prec(a[i])<=prec(Top(1)))
            {
                s[j++]=Top(1);
                pop();
            }
            c=a[i];
            push(1);
        }
    }
    while(!isEmpty())
    {
        s[j++]=Top(1);
        pop();
    }
    s[j]='\0';
    printf("Postfix : %s\n",s);
}

void evaluate(){
    int i,j;
    for(i=0;i<strlen(s);i++){
        if(isNum(s[i]))
        {
            j=0;
            char b[100];
            while(isNum(s[i]) && i<strlen(s))
                b[j++]=s[i++];
            i--;
            if(s[i]!=' ')
                i++;
            b[j]='\0';
            temp=atoi(b);
            push(2);
        }
        else if(s[i]==' ')
            i++;
        else
        {
            int x=Top(2);
            pop();
            int y=Top(2);
            pop();
            switch(s[i])
            {
                case '+':
                    temp=y+x;
                    push(2);
                    break;
                case '-':
                    temp=y-x;
                    push(2);
                    break;
                case '*':
                    temp=y*x;
                    push(2);
                    break;
                case '/':
                    temp=y/x;
                    push(2);
                    break;
                case '^':
                    temp=pow(y,x);
                    push(2);
                    break;
            }
        }
    }
}

int main(){
    gets(a);
    getpostfix();
    top=NULL;
    evaluate();
    printf("Result : %d",Top(2));
}
