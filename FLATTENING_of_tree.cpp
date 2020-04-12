#include <bits/stdc++.h>
using namespace std;
#define ll long int

vector<int > adj[100005];
int in[100005];
int out[100005];
int flatten[100005];
int vis[100005]={0};
int timer=1;
void dfs(int u){
    in[u]=timer++;
    flatten[u]=timer;
    vis[u]=1;
    for(auto i:adj[u]){
        if(!vis[i]){
            dfs(i);
        }
    }
    out[u]=timer++;
    flatten[u]=timer;
}
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
	    int x,y;
	    cin>>x>>y;
	    adj[x].push_back(y);
	    adj[y].push_back(x);
	}
	dfs(1);
	cout<<"Intime of nodes are:- ";
	for(int i=1;i<=n;i++){
	    
	    cout<<in[i]<<" ";
	}
	cout<<endl;
	cout<<"Outtime of nodes are:- ";
	for(int i=1;i<=n;i++){
	    
	    cout<<out[i]<<" ";
	}
	cout<<endl;
	cout<<"total timer is:- "<<timer<<endl;
	return 0;
}
