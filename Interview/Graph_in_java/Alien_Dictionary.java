class Solution {
    public String findOrder(String[] dict, int n, int k) {
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        int[] indegree = new int[k];
        
        for (int i = 0; i < k; i++) {
            graph.add(new ArrayList<>());
        }
        
        for (int i = 1; i < n; i++) {
            String a = dict[i];
            String b = dict[i-1];
            for (int j = 0; j < Math.min(a.length(), b.length()); j++) {
                if (a.charAt(j) != b.charAt(j)) {
                    int aa = a.charAt(j) - 'a';
                    int bb = b.charAt(j) - 'a';
                    graph.get(bb).add(aa);
                    indegree[aa]++;
                    break;  // Important: break after first mismatch
                }
            }
        }
        
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < k; i++) {
            if (indegree[i] == 0) {
                q.add(i);
            }
        }
        
        StringBuilder sb = new StringBuilder();
        while (!q.isEmpty()) {
            int x = q.poll();
            sb.append((char)(x + (int)'a'));
            for (int child : graph.get(x)) {
                indegree[child]--;
                if (indegree[child] == 0) {
                    q.add(child);
                }
            }
        }
        
        return sb.toString();
    }
}
