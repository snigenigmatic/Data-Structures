// implementing DFS for a graph represented as an adjacency list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node *next;
};

int visit[10];

void createGraph();
void insert(int, int);
void dfs(int);
void bfs(int);

int n;
struct node *a[100];

int main()
{
    int i, v, k;
    printf("Enter the number of vertices : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        a[i] = NULL;
    }

    createGraph();

    printf("Enter the starting vertex for DFS : ");
    scanf("%d", &v);

    for (i = 0; i < n; i++)
    {
        visit[i] = 0;
    }

    printf("The DFS traversal of the graph is : ");
    dfs(v);
    printf("\n");

    return 0;
}

void createGraph()
{
    int i, j;
    struct node *last, *tmp;

    for (i = 0; i < n; i++)
    {
        last = NULL;
        while (1)
        {
            printf("Enter the adjacent vertex of %d : ", i);
            scanf("%d", &j);
            if (j == -1)
                break;

            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->vertex = j;
            tmp->next = NULL;

            if (a[i] == NULL)
            {
                a[i] = tmp;
            }
            else
            {
                last->next = tmp;
            }
            last = tmp;
        }
    }
}

void dfs(int v)
{
    struct node *p;
    visit[v] = 1;
    printf(" %d", v);

    for (p = a[v]; p != NULL; p = p->next)
    {
        if (!visit[p->vertex])
        {
            dfs(p->vertex);
        }
    }
}

void insert(int i, int j)
{
    struct node *tmp, *last;

    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->vertex = j;
    tmp->next = NULL;

    if (a[i] == NULL)
    {
        a[i] = tmp;
    }
    else
    {
        last = a[i];
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = tmp;
    }
}

void bfs(int v)
{
    int w;
    struct node *p;
    visit[v] = 1;

    for(p = a[v];p!=NULL;p=p->next)
    {
        w = p->vertex;
        if(!visit[w])
        {
            visit[w] = 1;
            printf(" %d", w);
            bfs(w);
        }
        p = p->next;
    }
}
