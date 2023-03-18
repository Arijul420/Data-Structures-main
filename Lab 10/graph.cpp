#include<stdio.h>

int graph[200][200];

int main()
{
    int n,e;
    printf("Enter no of Node: \n");
    scanf("%d",&n);

    printf("Enter no of edge:\n");
    scanf("%d",&e);

    int so,des,we;
    for(int i=1;i<=e;i++)
    {
        scanf("%d %d %d",&so,&des,&we);
        graph[so][des]=we;
        graph[des][so]=we;
    }

    for(int i=1;i<=n;i++){
        for(int j=1; j<=n; j++){
            printf(" %d ",graph[i][j]);
        }
        printf("\n");
    }

    return 0;

}

