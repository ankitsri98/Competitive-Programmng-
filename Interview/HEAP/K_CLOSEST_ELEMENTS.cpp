class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int > v(arr.size());
        for(int i=0;i<arr.size();i++){
            v[i]=abs(arr[i]-x);
        }
        priority_queue<pair<int ,int > > pq;
        for(int i=0;i<arr.size();i++){
            pq.push({v[i],arr[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int > result;
        while(!pq.empty()){
            auto p=pq.top();
            result.push_back(p.second);
            pq.pop();
        }
        sort(result.begin(),result.end());
        return result;
    }
};