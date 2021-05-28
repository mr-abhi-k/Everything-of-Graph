/*
    (bfs)
    T.C : O(V+E)
    S.C : O(V)

    Psuedo code:-
    create a queue Q 
    mark v as visited and put v into Q 
    while Q is non-empty 
        remove the head u of Q 
        mark and enqueue all (unvisited) neighbours of u
*/
/*
7 
7
0 2
0 3
3 5
2 4
2 1
2 6
4 6
*/
#include<bits/stdc++.h>
using namespace std;
class Shadow
{
    public:
    vector<int> bfs(int V,vector<int> adj[],int src)
    {
        vector<int> ans; //ans array
        vector<int> vis(V,0); //visited array

        queue<int> que;
        que.push(src);
        vis[src]=1;
        
        while(!que.empty())
        {
            int node=que.front();
            ans.push_back(node);
            que.pop();
            for(auto i : adj[node])
            {
                if(!vis[i])
                {
                    que.push(i);
                    vis[i]=1;
                }
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
        vector<int> ans=obj.bfs(V,adj,src);
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}