#include <iostream>
using namespace std;

int adj[100][100], visited[100];

void dfs(int u, int n)
{
    visited[u] = 1;
    cout << u << " ";
    for (int v = 0; v < n; v++)
        if (adj[u][v] == 1 && visited[v] == 0)
            dfs(v, n);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(0, n);
}
