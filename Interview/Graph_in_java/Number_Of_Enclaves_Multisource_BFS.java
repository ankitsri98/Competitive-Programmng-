class Solution {
    boolean vis[][] = new boolean[502][502];
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    class Pair {
        int row;
        int col;
        Pair(int r, int c) {
            row = r;
            col = c;
        }
    }
    boolean valid(int i, int j, int n, int m) {
        if (i<0 || j<0 || i>=n || j>=m) {
            return false;
        }
        if (vis[i][j])return false;

        return true;
    }
    public int numEnclaves(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        Queue<Pair> q = new LinkedList<>();
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (i==0 || j==0 || i == n-1 || j == m-1) {
                    if(grid[i][j]==1) {
                        q.add(new Pair(i,j)); //Adding multisource for BFS
                        System.out.println(i + " -> " + j);
                        vis[i][j]=true;
                    }
                }
            }
        }
        // BFS logic 
        while(!q.isEmpty()) {
            Pair p = q.peek();
            int row = p.row;
            int col = p.col;
            System.out.println("bfs: " + row + " -> " + col);
            
            q.poll();
            for (int i=0;i<4;i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];
                if(valid(nr, nc, n, m) && grid[nr][nc]==1) {
                    q.add(new Pair(nr,nc));
                    vis[nr][nc] = true;
                }
            }
        }

        int ans =0;
        for(int i=0;i<n ;i++ ){ 
            for (int j=0;j<m;j++) {
                if(grid[i][j]==1 && vis[i][j]==false)ans++;
            }
        }

        return ans;
    }
}
