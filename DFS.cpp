#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
void DFS(int vertex)
{
    cout<<vertex<<" ";
    visited[vertex] = true;
    for (int child : adj[vertex])
        if (!visited[child])
            DFS(child);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    DFS(1);
}
