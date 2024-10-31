class Solution {
    static int[] bellmanFord(int V, ArrayList<ArrayList<Integer>> edges, int src) {
        int[] dist = new int[V];
        Arrays.fill(dist, (int) 1e8);
        
        dist[src] = 0;
        for (int i=0;i<V-1;i++) {
            for (var edge : edges) {
                int u = edge.get(0);
                int v= edge.get(1);
                int wt = edge.get(2);
                if(dist[u]!= 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        //Nth Itegration to check for -ve cycle
        for (var edge : edges) {
            int u = edge.get(0);
            int v= edge.get(1);
            int wt = edge.get(2);
            if(dist[u]!= 1e8 && dist[u] + wt < dist[v]) {
                int[] temp = new int[1];
                temp[0] = -1;
                return temp;
            }
        }

        return dist;
    } 
}
