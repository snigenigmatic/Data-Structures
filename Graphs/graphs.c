#include <stdio.h>
#include <stdlib.h>

void creategraph();
void display();
void dfs(int);
void bfs(int);

int adjmat[10][10], visit[10], q[25];
int n; // order of the matrix
int f = -1, r = -1;

void main()
{
    int v;
    printf("Enter the number of vertices : ");
    scanf("%d", &n);

    creategraph();
    display();

    printf("Enter the start vertex : ");
    scanf("%d", &v);

    for (int i = 0; i < n; i++)
    {
        visit[i] = 0;
    }
    printf("The graph traversal using BFS..\n");

    bfs(v);
}

void creategraph()
{
    int i, j;
    while (1)
    {
        printf("Enter the source and destination vertices : ");
        scanf("%d %d", &i, &j);
        if (i == -9 && j == -9)
            break;
        else
        {
            adjmat[i][j] = 1;
            adjmat[j][i] = 1; // undirected graph
        }
    }
}

void display()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("\t%d", adjmat[i][j]);
        printf("\n");
    }
}

void dfs(int v)
{
    int i;
    visit[v] = 1;
    printf(" %d", v);

    for (i = 1; i <= n; i++)
        if (visit[i] == 0 && adjmat[v][i] == 1)
            dfs(i);
}



// Breadth First Search
void qinsert(int v);
int qdelete();
int isEmpty();

void bfs(int v)
{
    int w;
    visit[v] = 1;
    printf(" %d", v);
    qinsert(v);
    while(!isEmpty())
    {
        v = qdelete();
        for(w = 1; w <= n; w++)
        {
            if(visit[w] == 0 && adjmat[v][w] == 1)
            {
                qinsert(w);
                printf(" %d", w);
                visit[w] = 1;
            }
        }
    }
}

void qinsert(int v)
{
    if(r == 24)
        printf("Queue Overflow\n");
    else
    {
        if(f == -1)
        {
            f = 0;
        }
        r = r + 1;
        q[r] = v;
    }
}

int qdelete()
{
    int v;
    if(f == -1 || f > r)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
    {
        v = q[f];
        f = f + 1;
        return v;
    }
}

int isEmpty()
{
    if(f == -1 || f > r)
        return 1;
    else
        return 0;
}