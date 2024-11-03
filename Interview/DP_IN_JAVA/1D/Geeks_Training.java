class Solution {
    int maxPoints(int i, int n, int flag, int[][] arr, int[][] dp) {
        if (i>=n) return 0;
        
        if(dp[i][flag]!=-1) return dp[i][flag];
        
        
        if (flag == 2) {
            dp[i][flag] = Math.max(dp[i][flag], Math.max(arr[i][1] + maxPoints(i+1, n, 1, arr,dp), arr[i][0] + maxPoints(i+1, n, 0, arr,dp)) );
        }
        if (flag == 1) {
            dp[i][flag] = Math.max(dp[i][flag], Math.max(arr[i][0] + maxPoints(i+1, n, 0, arr,dp), arr[i][2] + maxPoints(i+1, n, 2, arr,dp)));
        }
        if (flag == 0) {
            dp[i][flag] = Math.max(dp[i][flag], Math.max(arr[i][1] + maxPoints(i+1, n, 1, arr,dp), arr[i][2] + maxPoints(i+1, n, 2, arr,dp)));
        }
        return dp[i][flag];
    }
    public int maximumPoints(int arr[][], int N) {
        int[][] dp = new int[N+2][3];
        for (int i=0;i<N;i++) {
            Arrays.fill(dp[i],-1);
        }
        int ans = -1;
        for (int i=0;i<3;i++) {
            ans = Math.max(ans, maxPoints(0, N, i, arr, dp));
        }
        return ans;
    }
}
