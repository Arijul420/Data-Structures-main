#include <stdio.h>

int que[20];
int top = -1;

bool push(int x)
{
    top++;

    if(top>19){
        printf("overflow");
        return false;
    }
    else{
        que[top]=x;
        return true;
    }
}

int pop()
{
    if(top<0)
        return -1;
    else{
        int i,temp;
        temp=que[0];
        for(i=0;i<top;i++)
        {
            que[i]=que[i+1];
        }
        top--;
        return temp;
    }

}

bool isEmpty()
{
    if(top<0)
        return true;

    return false;
}

int queSize()
{
    return top+1;
}

void printAll()
{
    for(int i=0; i<=top; i++)
    {
        printf(" %d ",que[i]);
    }
    printf("\n");
}
void printOptions()
{
    printf("\n\n1.Push\n2.Pop\n3.IsEmpty?\n4.Queue Size?\n5.Print all\n6.End\n");
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
                printf("Queue is empty\n");

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
