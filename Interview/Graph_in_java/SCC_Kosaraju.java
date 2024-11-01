class Solution
{
    //KOSARAJU - ALGORITHM - SCC
    void dfs(int node, Stack<Integer> st, boolean[] vis, ArrayList<ArrayList<Integer>> adj) {
        vis[node] = true;
        for (var child : adj.get(node)) {
            if (vis[child]==false) dfs(child,st,vis,adj);
        }
        st.push(node);
    }
    public int kosaraju(int V, ArrayList<ArrayList<Integer>> adj)
    {
        int ans =0;
        /*
        Strongly Connected Components :- is a component in which any node can reach to any other
        Node in a Component and it is applicable to only directed graphs 
        Step 1: Store the nodes in the order of finishing time, first will be which finishes last
        Step 2: Reverse the graph edges
        Step 3: Do DFS -: the number of times DFS gets called we have that number of SCC
        */
        boolean[] vis = new boolean[V];
        Stack<Integer> st = new Stack<>();
        
        for (int i=0;i<V;i++) {
            if(vis[i]==false)dfs(i,st,vis, adj);
        }
        
        //Reversing the graph.
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for (int i=0;i<V;i++) {
            graph.add(new ArrayList<>());
            
        }
        //Remember how to convert into graph
        for (int i = 0; i < V; i++) {
            for (int v : adj.get(i)) {
                graph.get(v).add(i);
            }
        }
        // DFS again
         Arrays.fill(vis, false);
        while(!st.isEmpty()) {
            int x = st.pop();
            if(vis[x]==false){
                ans++;
                dfs(x,new Stack<>(),vis, graph);
            }
        }
        return ans;
        
    }
}
