#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Enter the number of nodes and edges: ";
    int n, e;
    cin >> n >> e;
    int adj[n + 1][n + 1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==j)
                adj[i][j]=0;
            else
                adj[i][j]=40;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int u, v,w;
        cin >> u >> v>>w;
        adj[u][v] = w;
    }
    cout<<"Adjacency Matrix: "<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
    cout<<"Transitive Closure Matrix: "<<endl;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}