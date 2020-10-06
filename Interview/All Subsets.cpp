void solve(vector<vector<int>> &v,int i,vector<int > &nums,vector<int > s){
        v.push_back(s);
        for (int j = i; j < nums.size(); j++) {
            s.push_back(nums[j]);
            solve(v,j+1,nums,s);
            s.pop_back();
        }
    }
