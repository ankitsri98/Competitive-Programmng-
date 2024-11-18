class Solution {
    int recur(int n , int s, int[] arr, int[][] dp) {
        
        if (n==0) return s%arr[0] == 0 ? 1 : 0;

        if (dp[n][s]!=-1) return dp[n][s];

        int notTake = recur(n-1,s,arr,dp);
        int take  = 0;
        if (s-arr[n]>=0) {
            take = recur(n,s-arr[n], arr, dp);
        }

        return dp[n][s] = take + notTake;
    }
    public int change(int amount, int[] coins) {
        int n = coins.length;
        int[][] dp = new int[n][amount+1];
        for (int i=0;i<n;i++){
            Arrays.fill(dp[i], -1);
        }
        return recur(n-1, amount, coins, dp);
    }
}
