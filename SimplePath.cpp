#include <bits/stdc++.h>
using namespace std;
const int N=1e5+20;
vector<int> adj[N];
bool vis[N];
void dfs(int vertex)
{
    cout<<vertex<<"->";
    vis[vertex]=true;
    for(int child : adj[vertex])
        if(!vis[child])
            dfs(child);
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    dfs(1);
    return 0;
}