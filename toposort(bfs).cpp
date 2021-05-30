#include<bits/stdc++.h>
using namespace std;

class Shadow
{
    public:
    vector<int> topo(int v,vector<int> adj[])
    {
        queue<int> q;
        vector<int> indeg(v,0);

        for(int i=0;i<v;i++)
        {
            for(auto j : adj[i])
            indeg[j]++;
        }

        for(int i=0;i<v;i++)
        {
            if(indeg[i]==0)
            q.push(i);
        }

        vector<int> ans;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto i : adj[node])
            {
                indeg[i]--;
                if(indeg[i]==0)
                q.push(i);
            }
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