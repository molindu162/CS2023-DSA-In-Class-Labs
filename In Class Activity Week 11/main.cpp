#include <iostream>
#include <vector>

using namespace std;

#define V 6

int minDistance(int dist[], bool visited[])
{
    int minDist = INT_MAX;
    int minIndex;
    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false && dist[v] <= minDist)
        {
            minDist = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

int printSolution(int dist[], int n, int source)
{
    cout << "Shortest time from city " << source << " to all other cities" << endl;
    printf("City \t\t time taken \n");

    for (int i = 0; i < V; i++){
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

void Dijkstra(int source, int graph[V][V])
{
    int dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[source] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);
        visited[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist, V, source);
    int sum = 0;
    for (int d : dist){
        sum += d;
    }
}


int main()
{
    int graph[V][V] = {
        {0 , 10, 0 , 0 , 15, 5 },
        {10, 0 , 10, 30, 0 , 0 },
        {0 , 10, 0 , 12, 5 , 0 },
        {0 , 30, 12, 0 , 0 , 20},
        {15, 0 , 5 , 0 , 0 , 0 },
        {5 , 0 , 0 , 20, 0 , 0 }
        };

    for (int i = 0; i < V; i++){
        Dijkstra(i, graph);
        cout << endl;
    }
    cout << endl;

    return 0;
}