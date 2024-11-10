class Solution {
    boolean palindrome(String s,int i,int j) {
        while(i<=j) {
            if (s.charAt(i)!=s.charAt(j)) {
                return false;
            }
            i++;--j;
        }
        return true;
    }
    int recur(int i,int n,int[] dp, String s) {
        if (i>=n) return 0;

        if (dp[i]!=-1) return dp[i];

        int minCut = Integer.MAX_VALUE;
        for (int k=i;k<n;k++) {
            if (palindrome(s,i,k)) {
                minCut= Math.min(minCut, 1 + recur(k+1,n,dp,s));
            }
        }
        return dp[i] = minCut;
    }
    public int minCut(String s) {
        // problem is based on front partition
        // f(i) = 1 + f(i+1) if we make a partition condition is  [0,i] string should be palindrome
        // we will only make a cut if left side is palindrom
        int n = s.length();
        int[] dp = new int[n+2];
        Arrays.fill(dp,-1);
        return recur(0,n,dp,s)-1;
    }
}
Complexity is N^2 due N states and N loop inside for partition
