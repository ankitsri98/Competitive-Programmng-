class Solution {
    int recur(int m, int n, int[][] dp) {
        //if (n<0 || m<0)return 0;
        if (n==0 || m==0)return 1;
        if (dp[m][n]!=-1) return dp[m][n];

        return dp[m][n] = recur(m-1,n,dp) + recur(m,n-1,dp);
    }
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
        for (int i=0;i<m;i++) {
            Arrays.fill(dp[i], -1);
        }
        return recur(m-1,n-1, dp);
    }
}
