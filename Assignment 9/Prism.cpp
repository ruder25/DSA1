#include <iostream>
using namespace std;

int adj[100][100], parent[100], key[100], inMST[100];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    for (int i = 0; i < n; i++)
    {
        key[i] = 100000;
        inMST[i] = 0;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int c = 0; c < n - 1; c++)
    {
        int min = 100000, u;
        for (int i = 0; i < n; i++)
            if (inMST[i] == 0 && key[i] < min)
            {
                min = key[i];
                u = i;
            }

        inMST[u] = 1;

        for (int v = 0; v < n; v++)
            if (adj[u][v] > 0 && inMST[v] == 0 && adj[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = adj[u][v];
            }
    }

    for (int i = 1; i < n; i++)
        cout << parent[i] << " " << i << " " << key[i] << endl;
}
