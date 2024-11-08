class Solution {
    int recur(int l ,int r,int[][] dp ,int[] cuts,int i , int j) {
        if (i>j) return 0;

        if (dp[i][j]!=-1) return dp[i][j];

        int cost = Integer.MAX_VALUE;
        for (int k=i;k<=j;k++ ) {
            if(cuts[k]>=l && cuts[k]<=r) {
                cost = Math.min(cost, (r-l) + recur(l,cuts[k],dp,cuts,i,k-1) + 
                                recur(cuts[k],r,dp,cuts,k+1, j));
            }
        }
        return dp[i][j] = cost;
    }
    public int minCost(int n, int[] cuts) {
        int s = cuts.length;
        int[][] dp = new int[s+2][s+2];
        for (int i=0;i<s;i++) {
            Arrays.fill(dp[i], -1);
        }
        Arrays.sort(cuts);
        return recur(0 , n, dp, cuts, 0,s-1);
    }
}
//complexity : S^2 * k
