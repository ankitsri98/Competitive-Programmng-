class Solution {

    static boolean recur(int n, int sum, Boolean[][] dp, int[] arr) {
        if (sum == 0) return true;
        if (n<0 && sum!=0) return false;
        
        if (dp[n][sum]!=null) return dp[n][sum];
        
        boolean a = false;
        boolean b = false;
        if (sum>=arr[n]) {
            a = recur(n-1,sum-arr[n], dp,arr);
        }
        b = recur(n-1,sum,dp,arr);
        return dp[n][sum] = a || b;
    }
    static Boolean isSubsetSum(int arr[], int sum) {
        int n = arr.length;
        Boolean[][] dp = new Boolean[n+2][sum + 2];
    
        
        return recur(n-1,sum,dp,arr);
    }
}
