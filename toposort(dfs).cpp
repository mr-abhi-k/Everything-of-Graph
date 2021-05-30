#include<bits/stdc++.h>
using namespace std;

class Shadow
{
    void dfshelp(int i, stack<int>&s, vector<int>&vis, vector<int> adj[])
    {
        vis[i]=1;
        for(auto it : adj[i])
        {
            if(!vis[it])
            dfshelp(it,s,vis,adj);
        }
        s.push(i);
    }

    public:
    vector<int> topo(int v,vector<int> adj[])
    {
        stack<int> s;
        vector<int> vis(v,0);

        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                dfshelp(i,s,vis,adj);
            }
        }
        vector<int> ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};

int main()
{
    int t;
    cin>>t;
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
            adj[v].push_back(u);
        }
        Shadow obj;
        vector<int> ans=obj.topo(V,adj);
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}