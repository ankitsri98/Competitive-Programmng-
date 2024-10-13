class Solution {
    // Function to detect cycle in a directed graph.
    boolean[] vis;
    boolean[] pathVisited;

    boolean dfs(int node, ArrayList<ArrayList<Integer>> adj) {
        vis[node] = true;
        pathVisited[node] = true;

        for (var child : adj.get(node)) {
            if (!vis[child]) {
                if (dfs(child, adj)) {
                    return true; // Cycle found
                }
            } else if (pathVisited[child]) {
                return true; // Cycle found (back edge)
            }
        }

        pathVisited[node] = false; // Backtrack
        return false; // No cycle found
    }

    public boolean isCyclic(int V, ArrayList<ArrayList<Integer>> adj) {
        vis = new boolean[V]; // Correct size
        pathVisited = new boolean[V]; // Correct size

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, adj)) {
                    return true; // Cycle found
                }
            }
        }
        return false; // No cycle found in the graph
    }
}
