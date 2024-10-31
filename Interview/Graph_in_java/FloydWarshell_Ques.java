class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
    
        int[][] cost = new int[n][n];
        for (int[] row: cost) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        for ( var row : edges) {
            int u = row[0];
            int v = row[1];
            int wt = row[2];
            cost[u][v]=wt;
            cost[v][u]=wt;
            
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++) {
                if (i==j)cost[i][i] = 0;
            }
        }

    
        for (int k=0;k<n;k++) {
            for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {
                    if(cost[i][k] == Integer.MAX_VALUE || 
                    cost[k][j] == Integer.MAX_VALUE) continue;
                    cost[i][j] = Math.min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }

        
            // for (int i=0;i<n;i++) {
            //     for (int j=0;j<n;j++) {
            //         System.out.print(cost[i][j] + " " );
            //     }
            //     System.out.println();
            // }
        

        int ans = Integer.MIN_VALUE;
        int cnt=Integer.MAX_VALUE;
        for (int i=0;i<n;i++) {
            int cnt1=0;
            for (int j=0;j<n;j++) {
                if (i!=j && cost[i][j]<=distanceThreshold) cnt1++;
            }
            // System.out.println(i + " -> " + cnt1);
            if(cnt1<=cnt) {
                cnt = cnt1;
                ans = i;
            }
        }
        return ans;
    }
}
