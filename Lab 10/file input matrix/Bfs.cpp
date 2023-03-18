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

void BFS(int adj[][SIZE] , int vertex , int startingNode);

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
    BFS(adj , vertex , 0);
}

void BFS(int adj[][SIZE] , int vertex , int startingNode)
{
    for(int i = 0 ; i < vertex ; i++)
    {
        if(i!= startingNode)
        {
            colour[i] = WHITE;
            dis[i] = INT_MIN;
            parent[i] = -1;
        }
    }

    colour[startingNode] = GRAY;
    dis[startingNode] = 0;
    parent[startingNode] = -1;
    queue <int> BFSQueue;
    BFSQueue.push(startingNode);
    printf("BFS is ");
    while(!BFSQueue.empty())
    {
        int u = BFSQueue.front();
        printf("%d ",u);
        BFSQueue.pop();
        for(int i = 0 ; i < vertex ; i++)
        {
            if(adj[u][i]!=0)
            {
                int v = i;
                if(colour[v] == WHITE)
                {
                    colour[v] = GRAY;
                    dis[v] = dis[u]+1;
                    parent[v] = u;
                    BFSQueue.push(v);
                }
            }
        }
        colour[u] = BLACK;
    }
}
