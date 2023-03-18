#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
//using namespace std;
struct Node
{
    char data;
    struct Node* next;
};
struct Node* top;
void push(char ch)
{
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=ch;
    if(top==NULL)
        newNode->next=NULL;
    else
        newNode->next=top;
    top=newNode;
}
void pop()
{
    if(top==NULL)
        return;
    else
    {
        struct Node *temp=top;
        top=temp->next;
        free(temp);
    }
}
char Top()
{
    return top->data;
}
bool isEmpty()
{
    if(top==NULL)
       return true;
    return false;
}
int main()
{
    top=NULL;
    char a[1000];
    printf("enter expression: ");
    gets(a);
    int i;
    for(i=0;i<strlen(a);i++)
    {
        if(isEmpty())
        {
            push(a[i]);
            continue;
        }
        if(a[i]=='(' || a[i]=='{' || a[i]=='[')
            push(a[i]);
        else
        {

            if(a[i]==')')
            {
                if(Top()=='(')
                    pop();
                else
                    break;
            }
            else if(a[i]=='}')
            {
                if(Top()=='{')
                    pop();
                else
                    break;
            }
            else if(a[i]==']')
            {
                if(Top()=='[')
                    pop();
                else
                    break;
            }
        }
    }
    if(isEmpty())
        puts("Balanced");
    else
        puts("Not balanced");
}
