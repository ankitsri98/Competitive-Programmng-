#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb push_back
#define nn 100005
vector<int > adj[nn];
vector<int > v(nn,0);
char arr[nn];
int tree[nn][27]={0};

void dfs(int u){
    v[u]=1;
    for(auto i:adj[u]){
        if(v[i]==0){
            dfs(i);
            //2:-so now the changes in leaf node is made which will be updated in its parent u and the child is 'i'
            for(int j=0;j<26;j++){
                tree[u][j]+=tree[i][j];//3:-its not necessary that this i always a leaf node , 
                //it can be a sub tree rooted with 'i' so all its changes will be reflected to this u by this loop
            }
        }
    }
    tree[u][arr[u]-'a']++;//1:-here u is a leaf node so every node as we know represents a character 
    //so we update that char. at that node. After that it get back to its parent and now that parent 
    //get updated with the value of leaf node(its child) becoz the logic is that subtree rooted at parent
    //will hold the complete length of string in its subtree
}
int main(){
    ll n,q,x,y,z;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        adj[x-1].pb(y-1);
        adj[y-1].pb(x-1);
    }
    dfs(0);//by simply calling dfs we have maintained all string a subtree can produce and then solved queries
    string s;
    while(q--){
        cin>>z>>s;
        ll ans=0;
        int freq[30]={0};
        for(ll i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        //now the tree that i have made in which each node is a root 
        //and with all the char. that its subtree has basically maintained a frequency
        for(int i=0;i<26;i++){
            ans+=max(0,freq[i]-tree[z-1][i]);
        }
        cout<<ans<<endl;
    }
}
