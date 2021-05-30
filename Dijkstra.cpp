//applicable for both directed and undirected 
//does not work with -ve weights
//done using priority queue with min heap;
//priority queue is already max heap

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int v,e,src;
	cin >> v >> e;
	vector<pair<int,int> > adj[v+1]; 	// 1-indexed adjacency list for of graph

	int a,b,wt;
	for(int i = 0; i<e ; i++)
    {
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	cout<<"enter source";
	cin >> src;
	
	// Dijkstra's algorithm begins from here
    priority_queue<pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>>> pq ; //weight ,node 
    //syntax check gfg

    vector<int> dist(v,INT_MAX);
    dist[src]=0;
    pq.push({0,src});

    while(!pq.empty())
    {
        int edgewt=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        for(auto i : adj[node])
        {
            int newEdgewt=i.first;
            int newNode=i.second;

            if(dist[newNode] > dist[node]+newEdgewt)
            {
                dist[newNode]=dist[node]+newEdgewt;
                pq.push(make_pair(dist[newNode], newNode));
            }
        }
    }

    for(int i=0;i<v;i++)
    {
        cout<<i<<"-->"<<dist[i]<<endl;
    }

    return 0;
}