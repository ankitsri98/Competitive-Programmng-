#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

vector<ll > adj[20];
vector<bool > visited(20,false);

void bfs(int x)
{
    queue<int > q;
    q.push(x);
    visited[x]=true ;
    while(!q.empty())
    {
        int m=q.front();
        cout<< m <<" ";
        q.pop();
        for(int j=0;j<adj[m].size();j++)
        {
            if(visited[adj[m][j]]==false)
            {
                q.push(adj[m][j]);
                visited[adj[m][j]]=true;
            }
        }
    }
}

int main()
{
    ll n,e,x,y;    //n=nodes e=edges
    cin>>n>>e;    //entering no. of node and edges

    for(int i=1;i<=e;i++)
    {
        cin>>x>>y;              //edges connection
        adj[x].pb(y);          //undirected graph
        //adj[y].pb(x);
    }

    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
            bfs(i);
    }
    return 0;
}
