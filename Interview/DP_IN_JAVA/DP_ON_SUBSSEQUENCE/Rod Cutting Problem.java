class Solution{
    int recur(int n, int[] dp, int[] arr) {
        if (n==0) return 0;
        
        if (dp[n]!=-1) return dp[n];
        int val = Integer.MIN_VALUE;
        for (int i=1;i<=n;i++) {
            if (n-i>=0) {
                val = Math.max(val, arr[i-1] + recur(n-i, dp, arr));
            }
        }
        //System.out.println(n + " -> " + val);
        return dp[n] = val;
    }
    public int cutRod(int price[], int n) {
        
        int[] dp = new int[n+1];
        Arrays.fill(dp, -1);
        return recur(n,dp,price);
    }
}
