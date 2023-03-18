#include<bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define SIZE 100

int adj[SIZE][SIZE];
int colour[SIZE];
int parent[SIZE];
int dis[SIZE];
int fin[SIZE];
int Time = 0;

void DFS(int vertex);
void DFS_Visit(int u , int vertex);

int main()
{
    freopen("Input.txt" , "r" , stdin);
    int vertex;
    int edge;
    scanf("%d",&vertex);
    scanf("%d",&edge);
    printf("Vertex is : %d\n",vertex);
    printf("Edge is : %d\n",edge);

    int node1,node2;
    for(int i = 0 ; i< edge ; i++)
    {
        scanf("%d",&node1);
        scanf("%d",&node2);
        adj[node1][node2] = 1;
        adj[node2][node1] = 1;

    }
    for(int i = 0 ; i < vertex ; i++)
    {
        for(int j = 0 ; j < vertex ; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    DFS(vertex);
}


void DFS(int vertex)
{
    for(int i = 0 ; i < vertex ; i++)
        colour[i] = WHITE;
    Time = 0;
    printf("DFS is ");
    for(int i = 0 ; i<vertex ; i++)
    {
        if(colour[i] == WHITE)
        {
            DFS_Visit(i , vertex);
        }
    }
}

void DFS_Visit(int u , int vertex)
{
    colour[u] = GRAY;
    dis[u] = Time++;
    for(int i = 0 ; i<vertex ; i++)
    {
        if(adj[u][i] == 1)
        {
            int v = i;
            if(colour[v] == WHITE)
            {
                parent[v] = u;
                DFS_Visit(v , vertex);
            }
        }
    }
    colour[u] = BLACK;
    fin[u] = Time++;
    printf("%d ",u);
}
