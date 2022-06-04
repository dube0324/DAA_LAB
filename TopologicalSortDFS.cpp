#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int cnt=0;
    vector<int> adj[n];
    vector<int> indeg(n,0);
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        indeg[v2]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(indeg[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        cnt++;
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        // for(int i=0;i<adj[node].size();i++)
        // {
        //     indeg[adj[node][i]]--;
        //     if(indeg[adj[node][i]]==0)
        //         q.push(adj[node][i]);
        // }
        for(int child:adj[node])
        {
            indeg[child]--;
            if(indeg[child]==0)
                q.push(child);
        }
    }
    return 0;
}