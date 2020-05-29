#include <bits/stdc++.h>
using namespace std;
typedef pair<int , pair<int ,int > >  custompair;

vector< int  > merge_k_sorted(vector< vector<int > > arr){
    vector<int > result;
    priority_queue< custompair, vector<custompair> , greater<custompair>  > pq;
    for(int i=0;i<arr.size();i++){
        pq.push({arr[i][0],{i,0}});
    }
    while(!pq.empty()){
        custompair p =pq.top;
        pq.pop();
        int x=p.second.first ;
        int y=p.second.second;
        result.push_back(p.first);
        if(y+1<arr[x].size()){
            pq.push({arr[x][y+1],{x,y+1}});
        }
    }
    return result;
}
int main() {
    int n,k;
    cin>>n>>k;
    vector< vector<int > > v(n , vector<int > (k,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>v[i][j];
        }
    }
    vector<int > output= merge_k_sorted(v);
    for(auto i: output){
        cout<<i<<" ";
    }
}
