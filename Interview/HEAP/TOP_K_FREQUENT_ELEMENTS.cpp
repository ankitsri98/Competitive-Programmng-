class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int > result;
        map<int ,int > mp;
        for(auto i: nums){
            mp[i]++;
        }
        priority_queue<pair<int,int >,vector<pair<int,int>>,greater<pair<int ,int>> > pq;
        for(auto i: mp){
            pq.push({i.second,i.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            auto p=pq.top();
            result.push_back(p.second);
            pq.pop();
        }
        return result;
    }
};