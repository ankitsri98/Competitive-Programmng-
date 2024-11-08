
class Solution{
    static int recur(int i, int j,int[] arr, int[][] dp) {
        if (i==j)return 0;
        
        if (dp[i][j]!=-1) return dp[i][j];
        
        int steps = Integer.MAX_VALUE;
        for (int k=i;k<j;k++) {
            steps = Math.min(steps, arr[i-1] * arr[k] * arr[j] + recur(i,k,arr,dp) + 
                            recur(k+1,j,arr,dp));
        }
        return dp[i][j] = steps;
    }
    static int matrixMultiplication(int N, int arr[])
    {
        int[][] dp = new int[N][N];
        for (int i=0;i<N;i++) {
            Arrays.fill(dp[i],-1);
        }
        return recur(1,N-1,arr,dp);
    }
}
