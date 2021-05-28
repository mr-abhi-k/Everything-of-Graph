#include<bits/stdc++.h>
using namespace std;
class Shadow
{
    
    void dfshelper(vector<int>adj[], int src, vector<int>&vis, vector<int> &ans)
    {
        ans.push_back(src);
        vis[src]=1;
        for(auto i : adj[src])
        {
            if(!vis[i])
            dfshelper(adj,i,vis,ans);
        }
    }

    public:
    vector<int> dfs(int v,vector<int> adj[],int src)
    {
        vector<int> ans;
        vector<int> vis(v+1,0);
        
        ans.push_back(src);
        vis[src]=1;

        for(auto i :adj[src])
        {
            if(!vis[i])
            {
                dfshelper(adj,i,vis,ans);
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
        
        cout<<"Enter the source vertex";
        int src;
        cin>>src;
        Shadow obj;
        vector<int> ans=obj.dfs(V,adj,src);
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}