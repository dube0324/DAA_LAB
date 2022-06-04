#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Enter the number of edges and nodes: ";
    int node, edges;
    cin >> node >> edges;
    int adj[node + 1][node + 1] = {0};
    for (int i = 1; i <= edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    cout << endl
         << "Adjacency Matrix: " << endl;
    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
    cout << endl
         << "Transitive Closure Matrix: " << endl;
    for (int k = 1; k <= node; k++)
    {
        for (int i = 1; i <= node; i++)
        {
            for (int j = 1; j <= node; j++)
            {
                adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
            }
        }
    }
    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}