#include <stdio.h>

int stc[20];
int top = -1;

bool push(int x)
{
    top++;
    if(top>19)
        return false;
    else
    {
        stc[top]=x;
        return true;
    }
}

int pop()
{
   int temp=stc[top];
   top--;
   return temp;
}

bool isEmpty()
{
   if(top<0)
     return true;
   return false;
}

int stackSize(){
   return top+1;
}

void printAll()
{
    for(int i=0; i<=top; i++)
    {
        printf(" %d ",stc[i]);
    }
    printf("\n");
}
void printOptions()
{
    printf("\n1.Push\n2.Pop\n3.IsEmpty?\n4.Stack Size?\n5.Print all\n6.End\n");
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
                printf("Stack is full\n");

            break;
        }
        case 2:
        {
            int x = pop();
            if(x>=0)
                printf("Successfully poped %d\n",x);
            else
                printf("Stack is empty\n");

            break;
        }
        case 3:
        {
            if(isEmpty())
                printf("Stack is empty\n");
            else
                printf("Stack is not empty\n");
            break;
        }
        case 4:
        {
            printf("Stack size %d\n",stackSize());
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
