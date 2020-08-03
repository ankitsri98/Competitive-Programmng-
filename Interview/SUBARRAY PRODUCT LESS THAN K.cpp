class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int s=0,res=0;
        int p=1;
        for(int e=0;e<nums.size();e++){
            p=p*nums[e];
            //ifproduct becomes greater than k shift s ->
            while(s<e && p>=k){
                p=p/nums[s];
                s+=1;
            }
            //if pro. is less than k count VIA Length
            if(p<k){
                int len=(e-s+1);
                res+=len;
            }
        }
        return res;
    }
};
