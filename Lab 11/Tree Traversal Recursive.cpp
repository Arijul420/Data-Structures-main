#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* right;
    Node* left;
};
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

void printPostorder(Node* node)
{
    if (node==NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ",node->data);
}
void printInorder(Node* node)
{
    if (node==NULL)
        return;
    printInorder(node->left);
    printf("%d ",node->data);
    printInorder(node->right);
}
void printPreorder(Node* node)
{
    if (node==NULL)
        return;
    printf("%d ",node->data);
    printPostorder(node->left);
    printPostorder(node->right);
}
int main()
{
    Node* root=NULL;
    int i,n,k;
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        root=Insert(root,k);
    }
    printf ("Post traversal : \n");
    printPostorder(root);
    printf ("\nInorder traversal : \n");
    printInorder(root);
    printf ("\nPreorder traversal : \n");
    printPreorder(root);
}
