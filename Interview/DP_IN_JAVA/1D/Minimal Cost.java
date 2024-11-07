class Solution {
    int recur(int n , int[] arr, int[] dp, int k) {
        if (n<=0)return 0;
        if (n==1) return Math.abs(arr[n]-arr[n-1]);
        
        if (dp[n]!= Integer.MAX_VALUE) return dp[n];
        int ans = Integer.MAX_VALUE;
        for (int i=1;i<=k;i++) {
            if (n - i >= 0) {
                ans = Math.min(ans, recur(n-i,arr,dp,k)+ Math.abs(arr[n-i]-arr[n]));
            }
        }
        return dp[n] = ans;
    }
    //whenever K is given consider it from 1 not 0
    // and try to manage that you dont pass negative index in recur as it throws array index out of bound
    public int minimizeCost(int k, int arr[]) {
        int N = arr.length;
        int[] dp = new int[N];
        Arrays.fill(dp, Integer.MAX_VALUE);
        return recur(N-1, arr, dp, k);
    }
}
