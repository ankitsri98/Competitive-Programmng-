class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        //BASICALLY WE HAVE TO TRACK THE REMAINDER IN THIS PROBLEM
        int sum=0,c=0;
        unordered_map< int ,int > mp;
        mp[0]++;
        for(auto i: A){
            sum+=i;
            int r=sum%K;
            if(r<0)r+=K;//if remainder is -ve then use this property to find the 
            //appropriate remainder
            if(mp.find(r)!=mp.end()){
                c+=mp[r];
            }
            mp[r]++;
        }
        return c;
    }
};
