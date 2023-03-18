#include<stdio.h>
#include<stdlib.h>
#define bool int


struct tNode
{
int data;
struct tNode* left;
struct tNode* right;
};


struct sNode
{
struct tNode *t;
struct sNode *next;
};


void push(struct sNode** top_ref, struct tNode *t);
struct tNode *pop(struct sNode** top_ref);
bool isEmpty(struct sNode *top);


void iterativePreorder(tNode *root)
{
    
    if (root == NULL)
       return;

    
    struct sNode *s = NULL;
    push(&s, root);

    while (!isEmpty(s))
    {
        
        tNode *node=pop(&s);
        printf ("%d ",node->data);


        if (node->right)
           push(&s,node->right);
        if (node->left)
            push(&s,node->left);
    }
}

void push(struct sNode** top_ref, struct tNode *t)
{

struct sNode* new_tNode =
			(struct sNode*) malloc(sizeof(struct sNode));


new_tNode->t = t;


new_tNode->next = (*top_ref);

(*top_ref) = new_tNode;
}


bool isEmpty(struct sNode *top)
{
    if(top==NULL)
        return true;
    return false;
}


struct tNode *pop(struct sNode** top_ref)
{
    struct tNode *res;
    struct sNode *top;



    top = *top_ref;
    res = top->t;
    *top_ref = top->next;
    free(top);
    return res;

}


struct tNode* newtNode(int data)
{
struct tNode* tNode = (struct tNode*)
					malloc(sizeof(struct tNode));
tNode->data = data;
tNode->left = NULL;
tNode->right = NULL;

return(tNode);
}


int main()
{


struct tNode *root = newtNode(10);
root->left	 = newtNode(8);
root->right	 = newtNode(2);
root->left->left = newtNode(3);
root->left->right = newtNode(5);
root->right->left=newtNode(2);

iterativePreorder(root);
getchar();
return 0;
}
