class Solution {
    int recur (int i, int j ,List<Integer> arr, int[][] dp) {
        if (i>j) return 0;

        if (dp[i][j]!=-1) return dp[i][j];

        int cost = Integer.MIN_VALUE;
        // will choose any one of it to be the last burst balloon
        // and this adding 1 to first and last will handle to take the appropriate last ballon with current
        for (int k=i;k<=j;k++) {
            cost = Math.max(cost, arr.get(i-1) * arr.get(k) * arr.get(j+1) + recur(i,k-1,arr,dp) + 
                            recur(k+1,j,arr,dp));
        }
        return dp[i][j] = cost;
    }
    public int maxCoins(int[] nums) {
        int n = nums.length;
        // if(n==1) return nums[0];
        List<Integer> arr = new ArrayList<>();
        arr.add(1);
        for (int i=0;i<n;i++) {
            arr.add(nums[i]);
        }
        arr.add(1);
        
        int[][] dp = new int[n+5][n+5];
        for (int i=0;i<=n;i++) {
            Arrays.fill(dp[i], -1);
        }
        return recur(1,n,arr,dp);
    }
}
