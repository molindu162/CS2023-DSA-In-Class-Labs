#include <iostream>

using namespace std;

#define V 6

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}

void primsMST(int graph[V][V])
{
    int parent[V];
    int keys[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
    {
        keys[i] = INT_MAX;
        mstSet[i] = false;
    }

    keys[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(keys, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < keys[v])
            {
                parent[v] = u;
                keys[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph);
}

int main()
{
    int graph[V][V] = {{0, 3, 0, 0, 0, 1},
                       {3, 0, 2, 1, 10, 0},
                       {0, 2, 0, 3, 0, 5},
                       {0, 1, 3, 0, 5, 0},
                       {0, 10, 0, 5, 0, 4},
                       {1, 0, 5, 0, 4, 0}};

    primsMST(graph);
}