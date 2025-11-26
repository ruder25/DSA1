#include <iostream>
using namespace std;

int adj[100][100], dist1[100], visited[100];

int main()
{
    int n, start;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    cin >> start;

    for (int i = 0; i < n; i++)
    {
        dist1[i] = 100000;
        visited[i] = 0;
    }

    dist1[start] = 0;

    for (int c = 0; c < n - 1; c++)
    {
        int min = 100000, u;
        for (int i = 0; i < n; i++)
            if (visited[i] == 0 && dist1[i] < min)
            {
                min = dist1[i];
                u = i;
            }

        visited[u] = 1;

        for (int v = 0; v < n; v++)
            if (adj[u][v] > 0 && visited[v] == 0 && dist1[u] + adj[u][v] < dist1[v])
                dist1[v] = dist1[u] + adj[u][v];
    }

    for (int i = 0; i < n; i++)
        cout << i << " " << dist1[i] << endl;
}
