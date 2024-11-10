class Solution {
    boolean recur(int n, int sum, Boolean[][] dp, int[] arr) {
        if (sum == 0) return true;
        if (n<0 && sum!=0) return false;
        
        if (dp[n][sum]!=null) return dp[n][sum];
        
        boolean a = false;
        boolean b = false;
        if (sum>=arr[n]) {
            a = recur(n-1,sum-arr[n], dp,arr);
        }
        b = recur(n-1,sum,dp,arr);
        return dp[n][sum] = a || b;
    }
    public boolean canPartition(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int sum = Arrays.stream(nums).sum();
        Boolean[][] dp = new Boolean[n+2][sum + 2];
        if (sum%2 ==0 ){
            return recur(n-1,sum/2,dp,nums);
        } else {
            return false;
        }
    }
    // if sum is even then only there is a possibility of getting equal sum partition ans.
}
