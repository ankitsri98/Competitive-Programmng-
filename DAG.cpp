#include <bits/stdc++.h>
using namespace std;

int in_deg[100005]={0};
vector<int > adj[100005];
vector<int > res;
int main() {
    int n,m;
    cin>>n>>m;
    int x,y;
    while(m--){
        cin>>x>>y;
        adj[x].push_back(y);
        in_deg[y]++;
    }
    queue<int > pq;
    for(int i=1;i<=n;i++){
        if(in_deg[i]==0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        int x=pq.front();
        pq.pop();
        res.push_back(x);
        for(auto i : adj[x]){
            in_deg[i]--;
            if(in_deg[i]==0){
                pq.push(i);
            }
        }
    }
    int dp[n]={0};
    int f_max=0;
    int node;
    for(int i=res.size()-1;i>=0;i--){
        //cout<<res[i]<<endl;
        int v=0;
        for(int j=0;j<adj[res[i]].size();j++){
            v=max(v,dp[adj[res[i]][j]]);
        }
        dp[res[i]]=1+v;
        if(f_max<dp[res[i]]){
            f_max=dp[res[i]];
            node=res[i];
        }
    }
    //for(int i=1;i<=n;i++){cout<<dp[i]<<" ";}
    cout<<f_max-1<<endl;
    cout<<node<<endl;
}
