class Solution {
    class Pair {
        int node;
        int weight;
        Pair(int a, int b) {
            node = a;
            weight = b;
        }
    }
    //we use bfs to ta go possible paths to get shortest distance 
    // as with the help of toposort we have got the path now
    // we will just update the distance with help of it

    public void dfs(ArrayList<ArrayList<Pair> > graph, Stack<Integer> st, int node, boolean[] vis) {
        vis[node] = true;
        for (Pair child : graph.get(node)) {
            if(vis[child.node] == false) {
                dfs(graph, st, child.node, vis);
            }
        }
    
        st.push(node);
    }
    public int[] shortestPath(int V, int E, int[][] edges) {
    
        int[] dist = new int[V];
        boolean[] vis = new boolean[V];
        ArrayList<ArrayList<Pair> > graph = new ArrayList<>();
        for (int i=0;i<V;i++) {
            graph.add(new ArrayList<Pair>());
        }
        for (int i=0;i<E;i++) {
            graph.get(edges[i][0]).add(new Pair(edges[i][1], edges[i][2]));
        }
        // for(int i=0;i<V;i++) {
        //     dist[i]= Integer.MAX_VALUE;
        // }
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[0]=0;
        //get toposort order
        Stack<Integer> st = new Stack<>();
        for (int i=0;i<V;i++) {
            if(vis[i] == false) {
                dfs(graph, st, i, vis);
            }
        }
    
        while(!st.isEmpty()) {
            int a = st.pop();
            //System.out.println(a);
            if (dist[a] != Integer.MAX_VALUE) {
                for (Pair child : graph.get(a)) {
                    if (dist[a] + child.weight < dist[child.node]) {
                        dist[child.node] = dist[a] + child.weight;
                    }
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]== Integer.MAX_VALUE) {
                dist[i] = -1;
            }
        }
        
        return dist;
    }
}
