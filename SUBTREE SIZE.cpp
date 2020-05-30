#include <bits/stdc++.h>
using namespace std;

vector<int > adj[1005];
vector<int > vis(1005);
vector<int > subtree(10,0);
int maxsize;
void dfs(int u){
    vis[u]=1;
    subtree[u]=1;
    for(auto i : adj[u]){
        if(vis[i]==0){
            dfs(i);
            subtree[u]+=subtree[i];//adding child size to parent
        }
    }
}
int main() {
    
    int n,e,x,y;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }
    dfs(1);
    for(int i=1;i<=4;i++){
        cout<<i<<" "<<subtree[i]<<endl;
    }
}
