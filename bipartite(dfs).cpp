#include<bits/stdc++.h>
using namespace std;
class Shadow
{
    bool checkBipartite(vector<int> adj[], int i, vector<int> &color)
    {
        for(auto it : adj[i])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[i];
                if(!checkBipartite(adj,it,color))
                return false;
            }
            else if(color[it]==color[i])
            return false;
        }
        return true;
    }

    public:
    bool isBipartite(int v, vector<int> adj[])
    {
        vector<int> color(v,-1);
        for(int i=0;i<v;i++)
        {
            if(color[i]==-1)
            {
                if(!checkBipartite(adj,i,color))
                return false;
            }
        }
        return true;
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
        if(obj.isBipartite(V,adj))
        cout<<"yes";
        else
        cout<<"No";
        cout<<endl;
    }
    return 0;
}