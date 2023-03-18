#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void sortedInsert(int value);
void insertFirst(int value);
void insertLast(int value);
void insertMiddle(int value);
void deleteItem(int value);
void displayList();


void sortedInsert(int value)
{
    struct node *newNode, *tempNode, *currentNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    tempNode=head;
    currentNode=head->next;
        while (currentNode != NULL && currentNode->data <= value)
        {
            tempNode = currentNode;
            currentNode = currentNode->next;
        }
        newNode->data = value;
        tempNode->next = newNode;
        newNode->next = currentNode;
        displayList();
}

void insertFirst(int value)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("UNABLE TO INSERT\n");
    }
    else
    {
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        printf("DATA INSERTED SUCCESSFULLY\n");
    }
    displayList();
}

void insertLast(int value)
{
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("UNABLE TO INSERT\n");
    }
    else
    {
        newNode->data = value;
        newNode->next = NULL;
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        printf("DATA INSERTED SUCCESSFULLY\n");
    }
    displayList();
}

void insertMiddle(int value)
{
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode)
    {
        newNode->data=value;
        newNode->next=NULL;
        if(head==NULL)
        {
            head=newNode;
            printf("DATA INSERTED SUCCESSFULLY\n");
        }
        else
        {
            struct node*temp=head,*help=head;
            while(temp&&temp->next&&temp->next->next)
            {
                help=help->next;
                temp=temp->next->next;
            }
            if(help)
            {
                newNode->next=help->next;
                help->next=newNode;
            }
            else
            {
                newNode->next=head->next;
                head->next=newNode;
            }
            printf("DATA INSERTED SUCCESSFULLY\n");
        }
    }
    else
    {
        printf("UNABLE TO INSERT\n");
    }
    displayList();
}

void deleteItem(int value)
{
    struct node *prev, *cur;
    while (head != NULL && head->data == value)
    {
        prev = head;
        head = head->next;
        free(prev);
        return;
    }
    prev = NULL;
    cur  = head;
    while (cur != NULL)
    {
        if (cur->data == value)
        {
            if (prev != NULL)
                prev->next = cur->next;
            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

void displayList()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        printf("Elements = ");
        while(temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int choice, item;
    do
    {
        printf("\nPlease Press \n'1' for Sorted Insert \n'2' for Insert at First \n'3' for Insert at Last \n'4' for Insert at Middle \n'5' for Delete \n'6' for Display \n'7' for Exit \n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter your element to insert: ");
            scanf("%d",&item);
            sortedInsert(item);
            break;
        case 2:
            printf("Enter your element to insert: ");
            scanf("%d",&item);
            insertFirst(item);
            break;
        case 3:
            printf("Enter your element to insert: ");
            scanf("%d",&item);
            insertLast(item);
            break;
        case 4:
            printf("Enter your element to insert: ");
            scanf("%d",&item);
            insertMiddle(item);
            break;
        case 5:
            printf("Enter your element to delete: ");
            scanf("%d",&item);
            deleteItem(item);
            displayList();
            break;
        case 6:
            displayList();
            break;
        case 7:
            printf("Exiting....");
            break;
        default:
            printf("Please Enter Your Choice Between 1 to 7\n");
        }
    }
    while(choice!=7);
    return 0;
}

