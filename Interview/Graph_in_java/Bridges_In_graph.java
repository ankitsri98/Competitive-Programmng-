class Solution {
    void dfs(ArrayList<ArrayList<Integer>> graph, int node, int parent,
    int timer, int[] inTime, int[] low, boolean[] vis, List<List<Integer>> ans) {
        inTime[node] = timer;
        low[node] = timer;
        vis[node] = true;
        timer++;
        for (var child : graph.get(node)) {
            //if child is equal to parent we have to avoid it
            if (child == parent) continue;

            if (vis[child]) {
                //if child is already visited that means there is a back edge from current node -> child node
                //As current node can be visited in shorted time from this node(child) so update the lowest time
                low[node] = Math.min(low[node],inTime[child]);
            } else {
                //when we apply visted to newly occurred node
                dfs(graph, child, node, timer, inTime, low, vis, ans);
                //Now is the time when we have covered whole tree from node(child)
                //We will try to update the low time of child which would have updated when there was a back edge of child node

                //Bridge Condition
                if (low[child] > inTime[node]) {
                    //means this child node has not encountered any back edge.
                    List<Integer> temp = new ArrayList<>();
                    temp.add(node);
                    temp.add(child);
                    ans.add(temp);
                }
                low[node] = Math.min(low[node], low[child]);
            }
        }
    }
    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        // Bridge edge in graph is an edge if removed increases the number of components in graph
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        int[] in = new int[n];
        int[] low = new int[n];
        boolean[] vis = new boolean[n];
        Arrays.fill(in,0);
        Arrays.fill(low,0);
        for (int i=0;i<n;i++) {
            graph.add(new ArrayList<>());
        }
        for (var row: connections) {
            graph.get(row.get(0)).add(row.get(1));
            graph.get(row.get(1)).add(row.get(0));
        }
        List<List<Integer>> ans = new ArrayList<>();
        dfs(graph,0,-1,0,in,low,vis, ans);

        return ans;
    }
}
