
https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?leftPanelTabValue=SUBMISSION

public class Solution {
    public static int minSubsetSumDifference(int []arr, int n) {
        int sum=0;
        for (int i=0;i<n;i++) {
            sum+=arr[i];
        }
        boolean[][] dp = new boolean[n][sum+2];
        
        for (int i=0;i<n;i++) {
            dp[i][0] = true;
        }
        if (arr[0] <= sum) {
            dp[0][arr[0]] = true;
        }
        
        for (int i=1;i<n;i++) {
            for (int j=1;j<=sum;j++) {
                boolean notTake  = dp[i-1][j];
                boolean take = false;
                if (j>=arr[i]) {
                    take = dp[i-1][j-arr[i]];
                }
                dp[i][j] = notTake || take;
            }
        }
        // for (int i=0;i<n;i++) {
        //     for (int j=0;j<=sum;j++) {
        //         System.out.print(dp[i][j] + " ");
        //     }
        //     System.out.println();
        // }
        // // exp is = 2*s1 - totalSum = diff
        int mi = Integer.MAX_VALUE;
        for (int i=0;i<=sum/2;i++) {
            if (dp[n-1][i]) {
                int s2 = sum -i;
                //System.out.println("S1 : " + i + "  s2: "  + s2 + " -> " + (s2-i));
                mi = Math.min(mi, Math.abs(s2-i));
            }
        }
        return mi;
    }
}
