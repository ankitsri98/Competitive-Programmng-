//USING DIJKTRAS IN O(V^2)

typedef pair<int ,pair<int ,int > > cmp;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector< pair<int ,int >  > adj[n+2];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        priority_queue<cmp, vector<cmp > ,greater<cmp> > pq;
        pq.push({0,{src,K+1}});
        while(!pq.empty()){
            //HERE NO CONCEPT OF VISITED ARRAY IS USED 
            cmp x=pq.top();
            pq.pop();
            int a=x.first,b=x.second.first,c=x.second.second;
            if(b==dst){
                return a;
            }
            if(c>0){
                for(int i=0;i<adj[b].size();i++){
                    pq.push({a+adj[b][i].second,{adj[b][i].first,c-1}});
                }
            }
        }
        return -1;
        
    }
};


USING DFS PRUNING
//IN THIS PROBLEM NO VISITED ARRAY IS USED AS IT IS DIRECTED GRAPH AND HAS NO CYCLE 

int p=INT_MAX;
vector< pair<int ,int >  > adj[105];
//make ans var global and try to write void function easy to memorize recursion
void dfs(int s,int d,int k,int res){
    
    if(s==d){//no problem if k>0 here as we haive to find min cost with in atmost k stations
        p=min(p,res);
        return ;
    }
    if(k==0){
        return ;
    }
    for(int i=0;i<adj[s].size();i++){
        pair x = adj[s][i];
       
        if(res+x.second>p)continue;//if we got any ans as p and now when im exploring other paths 
        //then i'll not check further in the path where this condition satisfies
        
        dfs(x.first,d,k-1,res+x.second);//always try to keep finding value track in function
    }
}
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        p=INT_MAX;
        dfs(src,dst,K+1,0);
        for(int i=0;i<n;i++){
            adj[i].clear();
        }
        if(p==INT_MAX){
            return -1;
        }
        return p;
    }
};



