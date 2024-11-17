
class Solution {
    private static final int MOD = 1000000007;
    public static int countPartitions(int n, int d, int[] arr) {
        
        int sum=0;
        for (int i=0;i<n;i++) {
            sum+=arr[i];
        }
        int s2 = sum - d;
        if (s2 < 0 || s2%2!=0) return 0;
        sum = s2/2;
        int[][] dp = new int[n][sum+1];
        //base case
        for (int i=0;i<=sum;i++) {
            if (i==0) {
                dp[0][i] = arr[0] == 0 ? 2 : 1;
            } else {
                dp[0][i] = arr[0] == i ? 1 : 0;
            }
        }
        //filling dp
        for (int i=1;i<n;i++) {
            for (int j=0;j<=sum;j++) {
                dp[i][j] = dp[i-1][j];
                if (j-arr[i]>=0) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-arr[i]])%MOD;
                }
            }
        }
        return dp[n-1][sum];
        
    }
}
        
