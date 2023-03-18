#include<stdio.h>


struct Node{
   int data;
   struct Node* next;

} Node;
struct Node* head;

void insert(int x){
   struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
   temp->data=x;
   temp->next=head;
   head=temp;
}

void print()
{
   struct Node* temp=head;
   printf("List is: ");
   while(temp!=NULL)
   {
      printf("%d ",temp->data);
      temp=temp->next;
   }
   printf("\n\n");
}
int main()
{
   head=NULL;
   int n,i,x;
   printf("How many numbers? ");
   scanf("%d",&n);
   printf("\n");

   for(i=0; i<n; i++)
   {
      printf("Enter the Number %d: ",i+1);
      scanf("%d",&x);
      printf("\n");
      insert(x);
      print();
   }
}

