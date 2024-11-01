class Solution
{
    void dfs(ArrayList<ArrayList<Integer>> graph, int node, int parent,
    int timer, int[] inTime, int[] low, boolean[] vis, Set<Integer> ans) {
        inTime[node] = timer;
        low[node] = timer;
        vis[node] = true;
        timer++;
        int children = 0;
        for (var child : graph.get(node)) {
            //if child is equal to parent we have to avoid it
            if (child == parent) continue;

            if (vis[child]) {
                //if child is already visited that means there is a back edge from current node -> child node
                //As current node can be visited in shorted time from this node(child) so update the lowest time
                low[node] = Math.min(low[node],inTime[child]);
            } else {
                children++;
                //when we apply visted to newly occurred node
                dfs(graph, child, node, timer, inTime, low, vis, ans);
                //Now is the time when we have covered whole tree from node(child)
                //We will try to update the low time of child which would have updated when there was a back edge of child node

               //This is the condition for articulation point
                if (parent!=-1 && low[child] >= inTime[node])  {
                    ans.add(node);
                }
                low[node] = Math.min(low[node], low[child]);
            }
        }
        // This condition is for root node if it hasmore than 1 child then it is an articulationpoint
        if (parent == -1 && children > 1) {
            ans.add(node);
        }
    }
    public ArrayList<Integer> articulationPoints(int V,ArrayList<ArrayList<Integer>> adj)
    {
        int[] in = new int[V];
        int[] low = new int[V];
        boolean[] vis = new boolean[V];
        Arrays.fill(in,0);
        Arrays.fill(low,0);
        
        Set<Integer> anss = new HashSet<>();
        dfs(adj,0,-1,0,in,low,vis, anss);
        if (anss.isEmpty()) {
            ArrayList<Integer> tmp = new ArrayList<>();
            tmp.add(-1);
            return tmp;
        }
        ArrayList<Integer> ans = new ArrayList<>(anss);
        Collections.sort(ans);
        return ans;
        
    }
}
