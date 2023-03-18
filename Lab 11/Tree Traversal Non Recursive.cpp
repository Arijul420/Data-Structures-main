#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* right;
    Node* left;
};
Node* root;
Node* create(int data)
{
    Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}
Node* Insert(Node* root,int data)
{
    if(root==NULL)
        root=create(data);
    else if(data<=root->data)
        root->left=Insert(root->left,data);
    else
        root->right=Insert(root->right,data);
    return root;
}

void post(Node* node)
{
    if (node==NULL)
        return;
    stack<Node*>s;
    stack<int>st;
    s.push(root);
    while(!s.empty())
    {
        Node* cur=s.top();
        s.pop();
        st.push(cur->data);
        if(cur->left)
            s.push(cur->left);
        if(cur->right)
            s.push(cur->right);
    }
    while(!st.empty())
    {
        printf("%d ",st.top());
        st.pop();
    }
}
void in(Node* node)
{
    if (node==NULL)
        return;
    stack<Node*>s;
    Node *cur=root;
    while (cur!=NULL || !s.empty())
    {
        while(cur!=NULL)
        {
            s.push(cur);
            cur=cur->left;
        }
        cur=s.top();
        s.pop();
        printf("%d ",cur->data);
        cur=cur->right;
    }
}
void pre(Node* node)
{
    if(node==NULL)
        return;
    stack<Node*>s;
    s.push(root);
    while(!s.empty())
    {
        struct Node* temp=s.top();
        s.pop();
        printf("%d ",temp->data);
        if(temp->right)
            s.push(temp->right);
        if(temp->left)
            s.push(temp->left);
    }
}
int main()
{
    root=NULL;
    int i,n,k;
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        root=Insert(root,k);
    }
    printf ("Post traversal : \n");
    post(root);
    printf ("\nInorder traversal : \n");
    in(root);
    printf ("\nPreorder traversal : \n");
    pre(root);
}
