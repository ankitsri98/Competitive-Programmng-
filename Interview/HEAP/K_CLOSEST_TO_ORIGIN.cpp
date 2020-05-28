#include<bits/stdc++.h>
using namespace std;

typedef pair<double, pair<int ,int > > cp;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int s=points.size();
        vector<double > dist(s);
        for(int i=0;i<s;i++){
            double val=sqrt(pow(points[i][0],2)+pow(points[i][1],2));
            dist[i]=val;
        }
        priority_queue<cp > pq;
        vector<vector<int  > > res(K,vector<int > (2));
        for(int i=0;i<s;i++){
            cout<<dist[i]<<endl;
            pq.push({dist[i],{points[i][0],points[i][1]}});
            if(pq.size()>K){
                pq.pop();
            }
        }
        int i=0;
        while(!pq.empty()){
            cp p=pq.top();
            cout<<p.first<<endl;
            res[i][0]=p.second.first;
            res[i][1]=p.second.second;
            pq.pop();
            i++;
        }
              return res;
    }
};