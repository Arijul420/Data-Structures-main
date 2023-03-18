#include <stdio.h>


int que[20];

int rear=-1;
int front=-1;

bool push(int x)
{
    if(rear==19)
        return false;
        else{

          if(front==-1)
             front=0;
        rear=rear+1;
        que[rear]=x;
        return true;
        }

}

int pop()
{
  int temp;
  if(front==-1)
     return -1;

     else{

     temp=que[front];
     printf("deleted element is %d\n",temp);
     front=front+1;
     return temp;
   }

}

bool isEmpty()
{
    if(front==-1)
        return true;
        else
            return false;

}

int queSize()
{
    int size;
    size=(rear-front)+1;
    return size;

}

void printAll()
{
    for(int i=front; i<=rear; i++)
    {
        printf(" %d ",que[i]);
    }
    printf("\n");
}
void printOptions()
{
    printf("\n\n1.Push\n2.Pop\n3.IsEmpty?\n4.Stack Size?\n5.Print all\n6.End\n");
    printf("Provide your choice: ");
}

int main()
{
    while(true)
    {
        int choice;
        bool needEnd = false;
        printOptions();
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
        {
            int x;
            scanf("%d",&x);

            if(push(x))
                printf("Successfully pushed\n");
            else
                printf("Queue is full\n");

            break;
        }
        case 2:
        {
            int x = pop();
            if(x>=0)
                printf("Successfully poped %d\n",x);
            else
                printf("queue is empty\n");

            break;
        }
        case 3:
        {
            if(isEmpty())
                printf("Queue is empty\n");
            else
                printf("Queue is not empty\n");
            break;
        }
        case 4:
        {
            printf("Queue size %d\n",queSize());
            break;
        }
        case 5:
        {
            printAll();
            break;
        }
        case 6:
        {
            needEnd = true;
            break;
        }
        default:
            printf("Invalid choice try Again.");
        }

        if(needEnd)
            break;
    }

    return 0;
}



