class Solution {
    int distinctWays(int i, int[] dp) {
        if (i==1) return 1;
        if (i==2) return 2;
        if (dp[i]!=-1) return dp[i];
        return dp[i]=distinctWays(i-1, dp) + distinctWays(i-2,dp);
    }
    public int climbStairs(int n) {
        int[] dp = new int[n+2];
        Arrays.fill(dp, -1);
        return distinctWays(n, dp);
    }
}
