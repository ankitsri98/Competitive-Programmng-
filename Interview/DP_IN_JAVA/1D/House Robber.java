class Solution {
    int recur(int n , int[] arr, int[] dp, int until) {
        if (n<until) return 0;
        
        if (dp[n]!= -1) return dp[n];
        
        return dp[n] = Math.max(arr[n] + recur(n-2,arr,dp, until), recur(n-1, arr, dp, until));
        
    }
    public int rob(int[] nums) {
        // f(n) = max(nums[n] + f(n-2) , f(n-1) )
        // first house connected to last mean circular 
        // 2 cases among them max is the ans
        // case 1 : [1,n-1];
        // case 2 : [0, n-1];
        int n = nums.length;
        if (n==1) return nums[0];
        int[] dp = new int[n];
        Arrays.fill(dp, -1);
        int a =  recur(n-1,nums,dp,1);
        Arrays.fill(dp, -1);
        int b = recur(n-2,nums,dp,0);
        System.out.println(a + " -> " + b);
        return Math.max(a,b);
    }
}
