import java.util.* ;
import java.io.*; 

public class Solution{
    private static int recur(int n, int[] arr, int[] val, int sum, int[][] dp) {
        if (n == 0) {
            return sum >= arr[0] ? val[0] : 0;
        }
        if (dp[n][sum] != -1) return dp[n][sum];
        
        int notTake = recur(n - 1, arr, val, sum, dp);
        int take = Integer.MIN_VALUE;
        
        if (sum - arr[n] >= 0) {
            int res = recur(n-1, arr, val, sum - arr[n], dp);
            if (res != Integer.MIN_VALUE) {
                take = val[n] + res;
            }
        }
        return dp[n][sum] = Math.max(take, notTake);
    }
    static int knapsack(int[] weight, int[] value, int n, int maxWeight) {

        int[][] dp = new int[n][maxWeight + 2];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }
        
        int res = recur(n - 1, weight, value, maxWeight, dp);
        
        return res == Integer.MIN_VALUE ? 0 : res;

    }
}
