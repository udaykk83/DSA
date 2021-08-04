#include<bits/stdc++.h>
using namespace std;

 
//to print the adjacency list representation of graph
void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
        printf("\n");
    }
}
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
    return 0;
}
/*int main(){
    
    int noV =5, noE=7;
    //cin>>noV>>noE;
    vector<int> adjList[noV+1]; 	
	// take edges as input 
	for(int i = 0;i<noE;i++) {
	    int u, v; 
	    cin >> u >> v;
	    adjList[u].push_back(v); 
	    adjList[v].push_back(u); 
	}
    return 0;
}*/