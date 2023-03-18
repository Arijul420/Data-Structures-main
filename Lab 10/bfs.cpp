#include<stdio.h>
int graph[200][200];
int que[200];
int top=-1;
int isVisited[500];

void push(int x)
{
    que[++top]=x;
}
int pop()
{
    int temp = que[0];
    for(int i=0;i<top;i++)
        que[i]=que[i+1];
    top--;
    return temp;
}
int queSize()
{
    return top+1;
}
bool isEmpty()
{
    if(top<0)
        return true;

    return false;
}
void inputGraph(int n, int e)
{
    int so, des, we;
    for(int i=1;i<=e;i++)
    {
        scanf("%d %d %d",&so, &des, &we);
        graph[so][des]=we;
        graph[des][so]=we;
    }

}
void printAM(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf(" %d ",graph[i][j]);
        }
        printf("\n");
    }
}


void bfs(int n)
{
    push(1);
    int t;
    isVisited[1]=1;
    while(!isEmpty())
    {
        t=pop();
        printf("%d ",t);
        for(int i=1; i<=n; i++)
        {
            if(graph[t][i]==1 && isVisited[i]==0)
            {
                push(i);
                isVisited[i]=1;
            }
        }

    }

}


int main()
{
    int n,e;
    printf("Enter no of Node: ");
    scanf("%d",&n);

    printf("Enter no of Edge: ");
    scanf("%d", &e);
    inputGraph(n,e);

    printAM(n);
    bfs(n);

    return 0;
}
