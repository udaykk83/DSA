#include<bits/stdc++.h>
using namespace std;

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

void dfsUtil(vector<int> adj[], vector<int> &dfs, vector<int> &vis, int node){
    dfs.push_back(node);
    vis[node] = 1;
    for(auto it : adj[node]){
        if(vis[it] != 1){
            dfsUtil(adj, dfs, vis, it);
        }
    }
}


vector<int> dfsGraph(vector<int> adj[],int v){
    vector<int> dfs;
    vector<int> vis(v+1, 0);
    
    for(int i=1; i<=v; i++){
        if(vis[i] != 1){
            dfsUtil(adj, dfs, vis, i);
        }
    }
   return dfs;
}



int main()
{
    int V = 5;
    vector<int> adj[V+1];
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    //printGraph(adj, V);
    vector<int> dfs = dfsGraph(adj,V);
    for(auto it : dfs){
        cout<< it<<" ->";
    }
    return 0;
}