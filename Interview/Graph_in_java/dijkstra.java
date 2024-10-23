class Solution {
    class Pair {
        int dist;
        int node;
        Pair(int a, int b) {
            dist = a;
            node = b;
        }
    }
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    ArrayList<Integer> dijkstra(ArrayList<ArrayList<iPair>> adj, int src) {
        // Write your code here
        
        int V = adj.size();
        ArrayList<Integer> distance = new ArrayList<>();
        for (int i = 0; i < V; i++) distance.add(Integer.MAX_VALUE);
        distance.set(src, 0);
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> Integer.compare(a.dist, b.dist));
        pq.offer(new Pair(0,src));
        
        while(!pq.isEmpty()) {
            Pair p = pq.poll();
            int node = p.node;
            int dist = p.dist;
            
            if (dist > distance.get(node)) continue;
            
            for (var pair : adj.get(node)) {
                int child = pair.first;
                int weight = pair.second;
                if (distance.get(node) + weight < distance.get(child)) {
                    distance.set(child, distance.get(node) + weight);
                    pq.offer(new Pair(distance.get(child), child));
                }
            }
        }
        return distance;
    }
    /*
    Note: This set approach cannot be implemented in JAVA by using TreeSet or HashSet. For implementing Dijkstra’s Algorithm in JAVA, we would use a priority queue only.

Time Complexity : O( E log(V) ) 

Where E = Number of edges and V = Number of Nodes.

Space Complexity : O( |E| + |V| ) 

Where E = Number of edges and V = Number of Nodes.
*/
}
