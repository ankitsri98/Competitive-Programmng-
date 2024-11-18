class Solution {
    int recur(int n, int[] arr, int s, int[][] dp) {
        if (n==0) return s%arr[0] == 0 ? s/arr[0] : Integer.MAX_VALUE;
       
       if (dp[n][s]!=-1) return dp[n][s];
        //System.out.println(n + " -> " + s);

        int take = Integer.MAX_VALUE;
        if (s-arr[n]>=0) {
            int subResult = recur(n, arr, s - arr[n], dp);
            if (subResult != Integer.MAX_VALUE) {
                take = 1 + subResult; // Take this coin
            }
        }

        int notTake = recur(n-1,arr,s,dp);
        
        return dp[n][s] = Math.min(take, notTake);
    }
    public int coinChange(int[] coins, int amount) {
        int n = coins.length;
        int[][] dp = new int[n][amount+1];
        for (int i=0;i<n;i++) {
            Arrays.fill(dp[i],-1);
        }
        int result =  recur(n-1, coins, amount, dp);
        return result == Integer.MAX_VALUE ? -1 : result ;
    }
}
