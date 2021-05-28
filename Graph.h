//graph heading for undirected
#include<bits/stdc++.h>
using namespace std;
void createGraph(bool flag=false)
{
    int t;
    while(t--)
    {
        int V,E;
        cin>>V>>E;
        vector<int> adj[V+1];
        for(int i=1;i<=E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            if(flag==true)
            adj[v].push_back(u);
        }
    }
}