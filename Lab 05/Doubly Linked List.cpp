#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node node;
node *root,*tail;

void insertfront(int data)
{
    node *nn=(node*)malloc(sizeof(node));

    nn->data=data;
    nn->next=nn;
    nn->prev=nn;

    if(root==NULL)
    {
        root=nn;
        tail=nn;
    }
    else
    {
        nn->next=root;
        nn->prev=tail;
        root->prev=nn;
        tail->next=nn;
        root=nn;
    }
}
void insertback(int data)
{
    node *nn=(node*)malloc(sizeof(node));

    nn->data=data;
    nn->next=nn;
    nn->prev=nn;

    if(root==NULL)
    {
        root=nn;
        tail=nn;
    }
    else
    {
        tail->next=nn;
        nn->next=root;
        nn->prev=tail;
        tail=nn;
        root->prev=tail;
    }
}

void deletefront()
{
    if(root==NULL)
        return;

    node *temp=root;

    tail->next=root->next;
    root=root->next;
    root->prev=tail;
    free(temp);
}

void deleteback()
{
    if(root==NULL)
        return;

    node *temp=root;
    node *cur=root;
    while(cur->next!=root)
    {
        temp=cur;
        cur=cur->next;
    }
    temp->next=root;
    tail=temp;
    root->prev=tail;
    free(cur);
}

void print()
{
    if(root==NULL)
        return;
    node *cur=root;
    printf("List : ");
    do
    {
        printf(" %d",cur->data);
        cur = cur->next;
    }while(cur != root);
}
int main()
{
    root=NULL;
    tail=NULL;
    int n,i,k;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&k);
        insertback(k);
    }
    print();
}
