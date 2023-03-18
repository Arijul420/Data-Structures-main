#include<stdio.h>
int graph[200][200];
int stc[200];
int top=-1;
int isVisited[200];

void push(int x)
{
    stc[++top]=x;
}
int pop()
{
    int temp=stc[top];
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
bool hasValidAdjNode(int n,int node)
{
    for(int i=1;i<=node;i++)
    {
        if(graph[n][i]==1 && isVisited[i]!=1)
            return true;
    }

        return false;
}
void dfs(int node)
{
    push(1);
    int p,flag;
    isVisited[1]=1;
    printf("%d ",stc[top]);

    while(!isEmpty())
    {

        p=stc[top];
        flag=0;
        for(int i=1; i<=node; i++)
        {
            if(graph[p][i]==1 && isVisited[i]==0)
                {
                    push(i);
                    isVisited[i]=1;
                    printf("%d ",i);
                    flag=1;
                    break;
                }
        }
        if(flag==0)
           pop();
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

    dfs(n);


    return 0;
}
