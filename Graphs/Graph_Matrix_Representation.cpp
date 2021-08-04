#include<bits/stdc++.h>
using namespace std;

int main(){
    //-------------->Matrix Representation
    int v = 5;
    int e = 3;
    vector<vector<int>> adjMat(v+1, vector<int>(v+1,0));
    for(int i = 0; i<e; i++){
        int u,v;
        cin>>u>>v;
        adjMat[u][v]=1;
        adjMat[v][u]=1;
    }//<------------------------------------

    return 0;
}
