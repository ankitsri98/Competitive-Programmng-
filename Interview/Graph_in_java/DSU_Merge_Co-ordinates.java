class Solution {
    int[] size = new int[200004];
    int[] par = new int[200004];
    int parent(int p) {
        if(p==par[p]) {
            return p;
        }
        return par[p]=parent(par[p]);
    }
    void merge(int a , int b) {
        int pa = parent(a);
        int pb = parent(b);
        if (pa==pb) return;
        if (size[pa]<size[pb]) {
            par[pa] = pb;
            size[pb]+=size[pa];
        } else {
            par[pb] = pa;
            size[pa]+=size[pb];
        }
    }
    public int removeStones(int[][] stones) {
    //in this question we are facing issue with uniqueness 
    // coz row and column both can be 0 , 1 , 2 ...
    // and one position is a unique and it will become uniqueu and (row,col)
    // will be unique that why row is from 1-10000 and col is from [1002-20000]
    // by this every point will become a unique point and concept that we use of merging(DSU)will work
    // logic is if there n components we can remove each element of comp. but not the last one
    // remove no. : comp1-1  + comp2 -1 + comp2-1
    // = comp1 + comp2 + comp3 - (1+1+1)
    // all comps are basically devided total n
    // = n- ( no. of components)
        for (int i=0;i<200004;i++) {
            par[i] = i;
            size[i] = 1;
        }
        HashMap<Integer, Integer> nodes = new HashMap<>();
        for (var row : stones) {
            merge(row[0], row[1]+100001);
            nodes.put(row[0],1);
            nodes.put(row[1]+100001,1);
        }

        // for (int i=0;i<10;i++) {
        //     System.out.print(size[i] + " ");
        // }
        // System.out.println();
        // for (int i=0;i<10;i++) {
        //     System.out.print(par[i]+ " ");
        // }

        // big ques how to find for what all nodes we need to check parent 
        // so for the nodes we call merge method we check parent of that
        // and for those nodes if node == parent[node]  then we found a parent of disjoint set
        int cnt = 0;
        for (var entry : nodes.entrySet()) {
            if (entry.getKey() == parent(entry.getKey())) {
                cnt++;
            }
        }
        //we can also use set

        return stones.length-cnt;
    }
}
