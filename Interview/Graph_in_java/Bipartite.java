class Solution {
    boolean[] vis;
    // maintaining color array is imp as in case of already visited node we want to know the color it was assigned earlier
    int[] color;
    boolean dfs(int node, int c, int[][] graph) {
        vis[node] = true;
        color[node] = c;

        for (int child : graph[node]) {
            if (!vis[child]) {
                // If the child hasn't been visited, recursively color it with the alternate color
                if (!dfs(child, 1 - c, graph)) {
                    return false; // Conflict found in the recursive call
                    //basically done coz if atleast false came even once we should 
                    //always return false, no need to check for next child 
                }
            } else if (color[child] == color[node]) {
                // If the child has been visited and has the same color as the current node
                return false; // Conflict found
            }
        }
        return true; // No conflicts found
    }
    public boolean isBipartite(int[][] graph) {
        
        int n = graph.length;
        vis = new boolean[n];
        color = new int[n];
         for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (!dfs(i, 0, graph)) {
                    return false;
                }
            }
        }
        return true;
    }
}
