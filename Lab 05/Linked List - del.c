#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node* head;

void Insert(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
//    temp->next = NULL;
//    if(head != NULL)
//        temp->next = head;
//    head = temp;
    temp->next = head;
    head = temp;

}
void Print()
{
    struct Node* temp = head;
    printf("List is:");
    while(temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void Delete(int n)
{
    struct Node* temp1 = head;
    if(n==1)
    {
        head = temp1->next;
        free(temp1);
        return;
    }
    int i;
    for(i=1;i<=n-2;i++)
        temp1=temp1->next;

    struct Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}
int main()
{
    head = NULL;
    printf("How many numbers?\n");
    int n,i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the number \n");
        scanf("%d",&x);
        Insert(x);
        Print();
    }

    printf("Enter a position\n");
    scanf("%d",&n);
    Delete(n);
    Print();
}

