class Solution {
    int recur(int m, int n, int[][] dp, int[][] obstacleGrid) {
        if (n<0 || m<0)return 0;
        if (obstacleGrid[m][n]==1) return 0;// we ignore that path
        if (n==0 && m==0)return 1; // and this condition will have && and till where ever
        // the robot can move it will have value 1 and once obstacle come we forbid that path
        if (dp[m][n]!=-1) return dp[m][n];

        return dp[m][n] = recur(m-1,n,dp, obstacleGrid) + recur(m,n-1,dp,obstacleGrid);
    }
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int n = obstacleGrid.length;
        int m = obstacleGrid[0].length;
        if (obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1) return 0;
        int[][] dp = new int[n][m];
        for (int i=0;i<n;i++) {
            Arrays.fill(dp[i], -1);
        }
        return recur(n-1,m-1, dp, obstacleGrid);
    }
}
