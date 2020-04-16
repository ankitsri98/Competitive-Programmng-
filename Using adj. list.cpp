#include <bits/stdc++.h>
using namespace std;
#define ll long int

vector<int > adj[100005];
int vis[100005]={0};
//FOR FINDING DIAMETER OF A TREE in O(2*N)~~O(N)
//TO FIND THE MAXIMUM DISTANCE FROM THE ROOT 
//WE USE THE CONCEPT OF THE CONCEPT OF LEVEL
int max_dis=-1,max_node;
void dfs(int u,int l){
    vis[u]=1;
    if(max_dis<l)max_dis=l,max_node=u;
    for(auto i:adj[u]){
        if(vis[i]==0){
            dfs(i,l+1);//level is passed as 2nd argument
        }
    }
}
//FINDING THE COUNT OF NODES IN ALL THE SUBTREE IN o(n)
int sub_tree_len[100005];
int dfs1(int u){
    vis[u]=1;
    int curr_size=1;
    for(auto i:adj[u]){
        if(!vis[i]){
            curr_size+=dfs1(i);
        }
    }
    sub_tree_len[u]=curr_size;
    return curr_size;
}
int main() {
	int n,t,m;
	    memset(vis,0,sizeof(vis));
	    for(int i=0;i<100005;i++){
	        adj[i].clear();
	    }
    	cin>>n;
    	for(int i=1;i<=n-1;i++){
    	    int x,y;
    	    cin>>x>>y;
    	    adj[x].push_back(y);
    	    adj[y].push_back(x);
    	}
    	dfs(1,0);
    	//cout<<max_node<<endl;
    	memset(vis,0,sizeof(vis));
    	max_dis=-1;
    	dfs(max_node,0);
    	cout<<max_dis<<endl;
    	
    	memset(vis,0,sizeof(vis));
    	cout<<"this is the count of total no. of nodes of tree rooted at  1 :- "<<dfs1(1)<<endl;
    	

	return 0;
}
