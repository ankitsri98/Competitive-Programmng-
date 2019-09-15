#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

vector<pair<ll,ll > > adj[20];
int dist[20];
void bfs(int x,int n)         //0-1 bfs concept of dijktra's algo.
{
    deque<int > q;
    q.pb(x);
    dist[x]=0;
    while(!q.empty())
    {
        int m=q.front();
        //cout<< m <<" ";
        q.pop_front();
        for(int j=0;j<adj[m].size();j++)
        {
           // cout<<dist[adj[m][j].first]<<" --> "<<dist[m]<<" "<<adj[m][j].second<<endl;
            if(dist[adj[m][j].first] > dist[m] + adj[m][j].second )
            {
                //cout<<"entered "<<dist[adj[m][j].first]<<" --> "<<dist[m]<<" "<<adj[m][j].second<<endl;
                dist[adj[m][j].first] = dist[m] + adj[m][j].second ;

                if(adj[m][j].second==0)
                    q.push_front(adj[m][j].first);    //this is done so that vertices
                else                                  //are traverse in increasing
                    q.push_back(adj[m][j].first);      //order of weights
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<< dist[i]<< " ";
}

int main()
{
    ll n,e,x,y,z;    //n=nodes e=edges
    cin>>n>>e;    //entering no. of node and edges
    for(int i=1;i<=e;i++)
    {
        cin>>x>>y>>z;              //x-->y  edges connection...corresponding z weight
        adj[x].push_back(make_pair(y,z));          //undirected graph
        adj[y].push_back(make_pair(y,z));
    }
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
    }
    bfs(0,n);
    return 0;
}
