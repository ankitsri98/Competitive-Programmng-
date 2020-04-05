#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
vector< pair<ll,ll > > adj[100005];
ll val[100005];
ll pre[100005]={0};
vector<ll > v(100005,0);
void dfs(int src){
    v[src]=1;
    for(auto i:adj[src]){
        if(v[i.first]==0){
            pre[i.first]=pre[src]+i.second;//at every node we precompute the 
            // total cost required to reach that node (for root its 0)
            dfs(i.first);
        }
    }
}
int main() {
    ll n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    int total=0;
    for(int i=0;i<=n-2;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        total+=c;//as we have to travel all the shows so we know by 1 dfs  
        //sum of cost of all the paths will be doublt of total if we end 
        //up at start(0);
        adj[a-1].push_back({b-1,c});
        adj[b-1].push_back({a-1,c});
    }
    dfs(0);
    total=2*total;
    ll ans=INT_MAX;
    for(int i=0;i<n;i++){
        ans=min(ans,val[i]+(total-pre[i]));//ans is calc by checking if from
        //particular node i we travel home then home cost for that node will 
        //be added and now we didnt move to node 1 from i so that cost will 
        //be removed so that will be the ans ;
    }
    cout<<ans<<endl;
    return 0;
}
