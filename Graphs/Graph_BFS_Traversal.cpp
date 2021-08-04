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

vector<int> bfsGraph(vector<int> adj[],int v){
    vector<int> vis(v+1,0);
    vector<int> bfs;
    for(int i = 1; i <= v; i++){
        if(vis[i] == 0){
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                int node = q.front();                
                q.pop();
                //cout<< node<<" ";
                bfs.push_back(node);
                for(auto it : adj[node]){
                    if(!vis[it]) {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    return bfs;
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
    vector<int> bfs = bfsGraph(adj,V);
    for(auto it : bfs){
        cout<< it<<" ->";
    }
    return 0;
}