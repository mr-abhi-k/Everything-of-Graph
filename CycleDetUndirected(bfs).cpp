#include<bits/stdc++.h>
using namespace std;

class Shadow
{
    bool checkForCycle(int s, int v, vector<int> adj[], vector<int> &vis)
    {
        //vector<int> parent(v,-1);

        queue<pair<int,int>> q;
        vis[s]=1;
        q.push({s,-1});

        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();

            for(auto i : adj[node])
            {
                if(!vis[i])
                {
                    q.push({i,node});
                    vis[i]=1;
                }
                else if(parent!=i) //node is not visited by its parent
                    return true;
            }
        }
        return false;
    }

    public:
    bool isCycle(int v, vector<int> adj[])
    {
        vector<int> vis(v,0);
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                if(checkForCycle(i,v,adj,vis))
                return true;
            }
        }
        return false;
    }
};

int main()
{
	int t;
	cin >> t;
	while(t--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++)
        {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		Shadow obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "Yes Cycle is present";
		else
            cout << "No Cycle is present";
	}
	return 0;
}