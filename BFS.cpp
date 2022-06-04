#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool visited[N];
vector<int> adj[N];
int main()
{
    for (int i = 0; i < N; i++)
        visited[i] = false;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int i = 0; i < adj[node].size(); i++)
        {
            if(!visited[adj[node][i]])
            {
                q.push(adj[node][i]);
                visited[adj[node][i]] = true;
            }
        }
        // for(int child : adj[node])
        // {
        //     if(!visited[child])
        //     {
        //         q.push(child);
        //         visited[child] = true;
        //     }
        // }
    }
        return 0;
    }