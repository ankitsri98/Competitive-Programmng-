
bool cmp(pair<string ,int > &a,pair<string ,int > &b ){
    return a.second<b.second || (a.second==b.second && a.first<b.first) ;
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
            vector<string > result;
            unordered_map<string ,int > mp;
            for(auto i: words){
                mp[i]++;
            }
            priority_queue<pair<int,string >,vector<pair<int,string>>, MyComp > pq;
            for(auto i: mp){
                //cout<<i.first<<endl;
                pq.push({i.second,i.first});
                if(pq.size()>k){
                    pq.pop();
                }
            }
            while(!pq.empty()){
                auto p=pq.top();
                result.insert(result.begin(), p.second);
                pq.pop();
            }
        //sort(result.begin(),result.end());
            return result;
    }
    
        private:
        struct MyComp {
            bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
                if(a.first != b.first) {
                    return a.first > b.first;
                }
                else {
                    return a.second < b.second;
                }
            }
        };
};

