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
int root1;


tNode* peek(struct sNode** top_ref)
{
     if (isEmpty(*top_ref))
        return NULL;
    struct tNode *res;
    struct sNode *top;

    top = *top_ref;
    res = top->t;
    return res;
}
void postOrderIterative(struct tNode* root)
{
    
    if (root == NULL)
        return;

   struct sNode *s = NULL;
    do
    {
        while (root)
        {
            
            if (root->right)
                push(&s, root->right);
            push(&s, root);
            root1=1;
            
            root = root->left;
        }

        root = pop(&s);


        if (root->right&& peek(&s) == root->right )
        {
            pop(&s); 
            push(&s, root);
            root = root->right; 
                                
        }
        else
        {
            printf("%d ", root->data);
            root = NULL;
        }

    } while (!isEmpty(s));

}

int main()
{


struct tNode *root = newtNode(1);
root->left	 = newtNode(2);
root->right	 = newtNode(3);
root->left->left = newtNode(4);
root->left->right = newtNode(5);


postOrderIterative(root);
getchar();
return 0;
}

