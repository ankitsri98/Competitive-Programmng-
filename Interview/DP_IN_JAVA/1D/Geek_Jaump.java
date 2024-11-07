class Solution{
    int recur(int n , int[] arr, int[] dp) {
        if (n<=0)return 0;
        if (n==1) return Math.abs(arr[n]-arr[n-1]);
        
        if (dp[n]!= Integer.MAX_VALUE) return dp[n];
        return dp[n] = Math.min(recur(n-1,arr,dp) + Math.abs(arr[n]-arr[n-1]),
                         recur(n-2,arr,dp) +  Math.abs(arr[n]-arr[n-2]));
        
    }
    public int minimumEnergy(int arr[],int N){
        // f(n) = min ( abs(f(n) - f(n-1)) , (f(n)-f(n-2))) 
        
        int[] dp = new int[N];
        Arrays.fill(dp, Integer.MAX_VALUE);
        return recur(N-1, arr, dp);
    }
}
