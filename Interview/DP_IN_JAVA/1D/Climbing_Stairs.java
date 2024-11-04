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


    Base cases:
        If i = 1, distinctWays(1) = 1
        If i = 2, distinctWays(2) = 2

    Recursive case: For i > 2: distinctWays(i) = distinctWays(i-1) + distinctWays(i-2)
