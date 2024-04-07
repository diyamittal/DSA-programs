#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    unordered_map<int, list<pair<int, int>>> adj;
    void addedge(int u, int v, int weight){
        pair<int, int> p=make_pair(v, weight);
        adj[u].push_back(p);
    }
    void printadj(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<")";
            }cout<<endl;
        }
    }
    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &topo){
        visited[node]=true;
        for(auto neighbour:adj[node]){
            if(!visited[neighbour.second]){
                dfs(neighbour.first, visited, topo);
            }
        }
        topo.push(node);
    }
    void getshortestpath(int src, vector<int> &dist, stack<int> &topo){
        dist[src]=0;
        while(!topo.empty()){
            int top=topo.top();
            topo.pop();
            if(dist[top]!=INT_MAX){
                for(auto i: adj[top]){
                    if(dist[top]+i.second<dist[i.first]){
                        dist[i.first]=dist[top]+i.second;
                    }
                }
            }
        }
    }
};
int main(){
    graph g;
    g.addedge(0,1,5);
    g.addedge(0,2,3);
    g.addedge(1,2,2);
    g.addedge(1,3,6);
    g.addedge(2,3,7);
    g.addedge(2,4,4);
    g.addedge(2,5,2);
    g.addedge(3,4,-1);
    g.addedge(4,5,-2);
    g.printadj();
    int n=6;
    unordered_map<int, bool> visited;
    stack<int> s;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.dfs(i, visited, s);
        }
    }
    int src=1;
    vector<int> dist(n);
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
    }
    g.getshortestpath(src, dist, s);
    cout<<"answer is"<<endl;
    for(int i=0;i<dist.size();i++){
        cout<< dist[i]<<" ";
    }cout<<endl;
    return 0;
}