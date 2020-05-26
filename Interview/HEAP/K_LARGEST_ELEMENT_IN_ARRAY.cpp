class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int , vector<int > ,greater<int> > pq;
        
        //always maintain heap of size k 
        // IF LARGEST REQUIRED THEN MAKE MIN-HEAP
        // ELSE MAKE MAX HEAP
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()<=k){
                continue;
            }
            else{
                pq.pop();
            }
        }
        return pq.top();
    }
};
