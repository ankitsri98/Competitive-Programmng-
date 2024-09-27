public class Solution {
    ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    boolean[] vis = new boolean[300000];
    boolean dfs(int node, int parent) {
        vis[node] = true;
        for (int child : graph.get(node)) {
            //covering true cases here and all other cases return false outside for loo[]
            if (vis[child]==false) {
                if(dfs(child, node)) {
                return true;
                }
            } else if (child != parent) { // if child is already visited and its not the parent(node) then it forms cycle
                return true;
            }
        }
        return false;
    }
    public int solve(int A, ArrayList<ArrayList<Integer>> B) {
        
        
        int m = B.size();
        for (int i=0;i<=A;i++) {
            graph.add(new ArrayList<>());
        }
        for (ArrayList<Integer> edge : B) {
            //consdering edge u->v
            int u = edge.get(0);
            int v = edge.get(1);
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        for (int i=1 ; i<=A;i++) {
            if((vis[i] == false)  && dfs(i,-1)) {
                return 1;
            }
        }
        return 0;
    }
}
