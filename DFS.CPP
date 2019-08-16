#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

vector<ll > adj[20];
vector<bool > visited(20,false);

void dfs(int x)
{
    visited[x]=true ;
    cout<< x <<" ";
    for(int j=0;j<adj[x].size();j++)
    {
        if(visited[adj[x][j]]==false){
            dfs(adj[x][j]);}
    }
}

int main()
{
    ll n,e,x,y;    //n=vertices e=edges
    cin>>n>>e;    //entering no. of node and edges

    for(int i=1;i<=e;i++)
    {
        cin>>x>>y;              //edges connection
        adj[x].pb(y);          //undirected graph
       // adj[y].pb(x);
    }

    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
            dfs(i);
    }
    return 0;
}
