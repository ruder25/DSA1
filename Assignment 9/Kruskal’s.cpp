#include <iostream>
using namespace std;

int parent[100];
int edges[100][3];

int find_set(int x)
{
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void union_set(int a, int b)
{
    int x = find_set(a);
    int y = find_set(b);
    parent[y] = x;
}

int main()
{
    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

    for (int i = 0; i < e; i++)
        for (int j = i + 1; j < e; j++)
            if (edges[i][2] > edges[j][2])
            {
                int t0 = edges[i][0];
                int t1 = edges[i][1];
                int t2 = edges[i][2];
                edges[i][0] = edges[j][0];
                edges[i][1] = edges[j][1];
                edges[i][2] = edges[j][2];
                edges[j][0] = t0;
                edges[j][1] = t1;
                edges[j][2] = t2;
            }

    for (int i = 0; i < 100; i++)
        parent[i] = i;

    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        if (find_set(u) != find_set(v))
        {
            union_set(u, v);
            cout << u << " " << v << " " << w << endl;
        }
    }
}
