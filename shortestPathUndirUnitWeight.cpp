#include<bits/stdc++.h>
using namespace std;
class Shadow
{
    //using bfs
    public:
    vector<int> shortestPath(int v, vector<int> adj[],int src)
    {
        vector<int> dis(v,INT_MAX);
        queue<int> q;

        q.push(src);
        dis[src]=0;

        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            for(auto i :adj[node])
            {
                if(dis[i]>dis[node]+1)
                {
                    dis[i]=dis[node]+1;
                    q.push(i);
                }
            }
        }
        return dis;
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

        cout<<"Enter source vertex";
        int src;
        cin>>src;

        Shadow obj;
        vector<int> ans=obj.shortestPath(V,adj,src);
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}