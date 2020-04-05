#include<bits/stdc++.h>
#define ll long long int 
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define nn 100005
#define mod 1000000007
using namespace std;
vector<ll > adj[nn];
vector<int> v(nn,0);
ll val[nn];

void bfs(int src,int x){
    queue<ll > q;
    q.push(src);
    v[src]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(((adj[u].size()<2 && u==0) || adj[u].size()<3 && u!=0)){
            //if node is root and its children are 1 then attach there else if node is
            //is not root and length less than 2 then attach to that node
            adj[u].push_back(x);
            adj[x].push_back(u);
            break;//break is used because we are moving from top and we have to 
            //minimize the sum so if we add new node value to some deeper node 
            //then it will increase the sum by getting adding up again and again;
        }
        for(auto i:adj[u]){
            if(v[i]==0){
                v[i]=1;
                q.push(i);
            }
        }
    }
}
ll ans;//keep the sum of all the nodes of tree
ll dfs(int src){
    v[src]=1;
    ll sum=val[src];
    for(auto i : adj[src]){
        if(v[i]==0){
            sum+=dfs(i);//when this loop ends it maintains the sum of subtree rooted
            //at 'src' 
        }
    }
    ans+=sum;//if it moves here without entering the loop then its the leaf node
    return sum;//return leaf node value in that case
}
int main() {
    FIO;
    ll n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    val[n]=x;
    for(int i=0;i<=n-2;i++){
        ll u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    bfs(0,n);//is used just to find the optimal position to attach the new node
    for(int i=0;i<nn;i++){
        v[i]=0;
    }
    dfs(0);
    //cout<<dfs(0)<<endl;
    cout<<ans<<endl;
    return 0;
}
