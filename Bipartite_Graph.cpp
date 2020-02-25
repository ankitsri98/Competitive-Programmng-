#include <bits/stdc++.h>
using namespace std;

vector<int > adj[100005];
bool bipartite(int n){
    unordered_set<int > s[2];
    s[0].insert(1);
    queue<int > q;
    q.push(1);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        int curr_set= s[0].count(x)>0 ? 0:1;
        for(int i=0;i<adj[x].size();i++){
            int adjacent=adj[x][i];
            if(s[0].count(adjacent)==0 && s[1].count(adjacent)==0){//if adj. is not present in any set
                s[1-curr_set].insert(adjacent);  // then put it in opposite set of that of parent 
                q.push(adjacent);
            }
            else if(s[curr_set].count(adjacent)>0){ //if adj is present in same set then return false
                return false;
            }
        }
    }
    return true;
}

int main() {
   
    int n,e,x,y;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(bipartite(n)){
        cout<<"Graph is bicolourable"<<endl;
    }
    else{
        cout<<"Graph is not bicolourable"<<endl;
    }
}
