class Solution {
    class Pair {
        int node;
        int distance;
        Pair(int a, int b) {
            node = a;
            distance = b;
        }
    }
    
    public int[] shortestPath(int[][] edges,int n,int m ,int src) {
        ArrayList<ArrayList<Integer> > graph = new ArrayList<>();
        for (int i=0;i<n;i++) {
            graph.add(new ArrayList<>());
        }
        for (int i=0;i<m;i++) {
            graph.get(edges[i][0]).add(edges[i][1]);
            graph.get(edges[i][1]).add(edges[i][0]);
        }
        
        int[] dist = new int[n];
        for (int i=0;i<n;i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        dist[src]=0;
        Queue<Pair> q = new LinkedList<>();
        
        q.add(new Pair(src,0));
        
        while(!q.isEmpty()) {
            Pair a = q.poll();
            int vetex = a.node;
            int d = a.distance;
            for (var child : graph.get(vetex)) {
                if (d + 1 < dist[child]) {
                    dist[child] = d + 1;
                    q.add(new Pair(child, d+1));
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i]== Integer.MAX_VALUE) {
                dist[i] = -1;
            }
        }
        
        return dist;
        
    }
    
    /*
    Time Complexity: O(M) { for creating the adjacency list from given list ‘edges’} + O(N + 2M) { for the BFS Algorithm} + O(N) { for adding the final values of the shortest path in the resultant array} ~ O(N+2M). 

Where N= number of vertices and M= number of edges.

Space Complexity:  O( N) {for the stack storing the BFS} + O(N) {for the resultant array} + O(N) {for the dist array storing updated shortest paths} + O( N+2M) {for the adjacency list} ~ O(N+M) .

Where N= number of vertices and M= number of edges.
*/
}
