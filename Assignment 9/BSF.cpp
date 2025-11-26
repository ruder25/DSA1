#include <iostream>
using namespace std;

int adj[100][100], visited[100];

void bfs(int start, int n)
{
    int q[100], front = 0, rear = 0;
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    q[rear++] = start;
    visited[start] = 1;
    while (front < rear)
    {
        int u = q[front++];
        cout << u << " ";
        for (int v = 0; v < n; v++)
            if (adj[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                q[rear++] = v;
            }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    bfs(0, n);
}
