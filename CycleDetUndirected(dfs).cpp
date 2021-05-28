#include<bits/stdc++.h>
using namespace std;
class Shadow
{
    bool checkForCycle(vector<int> adj[],int parent, int i, vector<int>&vis)
    {
        vis[i]=1;
        for(auto it : adj[i])
        {
            if(!vis[it])
            {
                if(checkForCycle(adj,i,it,vis)) //deep down the process
                return true;
            }
            else if(it!=parent) 
            return true;
        }
        return false;
    }

    public:
    bool isCycle(int v, vector<int>adj[])
    {
        vector<int> vis(v,0);
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                if(checkForCycle(adj,-1,i,vis))
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