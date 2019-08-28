#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

vector<pair<ll,ll > > adj[20];
int dist[20];
void bellman(int x,int n)         //concept of dijktra's algo.
{                                 //for -ve weights
    dist[x]=0;                    // should not contain -ve weight cycle
    for(int k=1;k<=n-1;k++)
    {
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            //cout<<dist[adj[i][j].first]<<" --> "<<dist[i]<<" "<<adj[i][j].second<<endl;
            if( dist[i]!=INT_MAX && dist[adj[i][j].first] > dist[i] + adj[i][j].second )
            {
                dist[adj[i][j].first] = dist[i] + adj[i][j].second ;
               // cout<<"entered "<<dist[adj[i][j].first]<<" --> "<<dist[i]<<" "<<adj[i][j].second<<endl;
            }
        }
    }
    }
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            if( dist[i]!=INT_MAX && dist[adj[i][j].first] > dist[i] + adj[i][j].second )
            {
                cout<<"graph contains negative weight cycle"<<endl;
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<< i <<"  " <<dist[i]<<endl;
}

int main()
{
    ll n,e,x,y,z;    //n=nodes e=edges
    cin>>n>>e;    //entering no. of node and edges
    for(int i=1;i<=e;i++)
    {
        cin>>x>>y>>z;              //x-->y  edges connection...corresponding z weight
        adj[x].push_back(make_pair(y,z));          //undirected graph
        //adj[y].push_back(make_pair(y,z));
    }
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
    }
    bellman(0,n);
    return 0;
}
