class Solution {
    int recur(int n, int m,int[][] grid, int[][] dp) {
        if(n<0 || m<0) return Integer.MAX_VALUE;
        if (n==0 && m==0) return grid[n][m];
        // just try to fond recurrence relation and base condition will be the above one mostly
        // coz that is the point we will return the value and further it will just keep
        //following recurrence and adding values.

        if (dp[n][m]!=Integer.MAX_VALUE) return dp[n][m];

        return dp[n][m] = grid[n][m] + Math.min(recur(n-1,m,grid,dp) , recur(n,m-1,grid,dp));
    }
    public int minPathSum(int[][] grid) {
        int n= grid.length;
        int m = grid[0].length;

        int[][] dp = new int[n][m];
        for (int i=0;i<n;i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }
        return recur(n-1,m-1,grid,dp);
    }
}
