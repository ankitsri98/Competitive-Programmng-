class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
       ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for(int i=0;i<numCourses;i++) {
            graph.add(new ArrayList<>());
        }
        int n = prerequisites.length;
        int[] indegree = new int[numCourses];
        for( int i=0;i<n;i++) {
            graph.get(prerequisites[i][1]).add(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        Queue<Integer> q = new LinkedList<>();
        for( int i=0;i<numCourses;i++) {
            if(indegree[i]==0) {
                q.add(i);
            }
        }
        int[] ans = new int[numCourses];
        int i=0;
        while(!q.isEmpty()) {
            Integer x = q.poll();
            ans[i++] = x;
            for (var child : graph.get(x)) {
                indegree[child]--;
                if (indegree[child]==0) {
                    q.add(child);
                }
            }
        }

        return i == numCourses ? ans : new int[0]; 

    }
}
