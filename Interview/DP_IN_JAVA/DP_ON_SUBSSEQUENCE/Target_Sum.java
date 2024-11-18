 class Solution {
    int recur(int n , int[] arr, int[][] dp, int s,int offset) {
         if (n == -1) {
            return s == 0 ? 1 : 0;
        }
        if (s + offset < 0 || s + offset >= dp[0].length) {
            return 0;
        }
        if (dp[n][s+offset]!=-1) return dp[n][s+offset];
        int add = recur(n-1,arr,dp, s+arr[n], offset);
        int sub = recur(n-1,arr,dp, s-arr[n], offset);

        return dp[n][s+offset]=add + sub;
    }
    public int findTargetSumWays(int[] nums, int target) {
        int n = nums.length;
        int sum = 0;
        for (int i=0;i<n;i++) {
            sum+=nums[i];
        }
        // sum value is taken this as there will be negative values as well and max it can go
        // till -sum when we use (-) infront of each element so tried making it +ve
        int[][] dp = new int[n][5*sum+10];
        for (int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return recur(n-1, nums, dp, target, sum);
    }
}

-----------------------------------------------------

  Another Solution :

class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        // narrowing the ques into s1-s2 = d
        // if some part of array is using + and some - then 2 subsets will be formed whose
        // diff will be target so we are just counting no. of S2's formed from diff(target)
        int n = nums.length;
        int sum=0;
        for (int i=0;i<n;i++) {
            sum+=nums[i];
        }
        int s2 = sum - target;
        if (s2 < 0 || s2%2!=0) return 0;
        sum = s2/2;
        int[][] dp = new int[n][sum+1];
        //base case
        for (int i=0;i<=sum;i++) {
            if (i==0) {
                dp[0][i] = nums[0] == 0 ? 2 : 1;
            } else {
                dp[0][i] = nums[0] == i ? 1 : 0;
            }
        }
        //filling dp
        for (int i=1;i<n;i++) {
            for (int j=0;j<=sum;j++) {
                dp[i][j] = dp[i-1][j];
                if (j-nums[i]>=0) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-nums[i]]);
                }
            }
        }
        return dp[n-1][sum];
    }
}
