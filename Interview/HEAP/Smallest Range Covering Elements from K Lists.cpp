typedef pair<int , pair<int ,int > >  custompair;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int low=INT_MAX;
        int high=INT_MIN;
        priority_queue< custompair, vector<custompair> , greater<custompair>  > pq;//creating min-heap
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i][0],{i,0}});//inserting first element of all the arrays
            low=min(low,nums[i][0]);
            high=max(high,nums[i][0]);
        }
        vector<int > res(2);
        res[0]=low;
        res[1]=high;
        while(!pq.empty()){
            custompair p =pq.top();//take  out th min.
            pq.pop();
            int x=p.second.first ;
            int y=p.second.second;
            if(y+1==nums[x].size()){
                break;
            }
            //so the logic is for any heap of size K top is the "low" and the element that we are gonna                 insert may be the "high"  
            if(y+1<nums[x].size()){//check if the min ele. array is not empty
                pq.push({nums[x][y+1],{x,y+1}});
                high=max(high,nums[x][y+1]);
                low=pq.top().first;
                if(high-low<res[1]-res[0]){
                    res[0]=low;
                    res[1]=high;
                }
            }
        }
        return res;
    }
};