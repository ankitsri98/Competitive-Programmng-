#include <bits/stdc++.h>
using namespace std;
#define ll long int

vector<int > adj[100005];
int vis[100005]={0};
int color[100005];

bool dfs(int u,int c){
    color[u]=c;
    vis[u]=1;
    for(auto i:adj[u]){
        if(vis[i]==0){
            bool res=dfs(i,c^1);
            //result returned by already visited node
            if(res==false){
                return false;
            }
        }
        else{
            //if its already visited
            if(color[u]==color[i])
            return false;
        }
     }
    return true;
}
int main() {
	int n,t,m;
	cin>>t;
	for(int i=1;i<=t;i++){
	    memset(vis,0,sizeof(vis));
	    memset(color,-1,sizeof(color));
	    for(int i=0;i<2005;i++){
	        adj[i].clear();
	    }
    	cin>>n>>m;
    	for(int i=1;i<=m;i++){
    	    int x,y;
    	    cin>>x>>y;
    	    adj[x].push_back(y);
    	    adj[y].push_back(x);
    	}
    	//as question contain various connected components
    	bool b,flag=true;
    	for(int i=1;i<=n;i++){
    	    if(!vis[i]){ 
    	        
    	        b=dfs(i,0);
    	        
    	        if(b==false){
    	            flag=false;
    	        }
    	    }
    	}
    	if(flag==false){
    	    cout<<"Scenario #"<<i<<":"<<endl;
    	    cout<<"Suspicious bugs found!"<<endl;
    	}
    	else{
    	    cout<<"Scenario #"<<i<<":"<<endl;
    	    cout<<"No suspicious bugs found!"<<endl;
    	    
    	}	    
	}

	return 0;
}
