import java.util.*;

public class Solution {
    static int parent(int p, int[] par) {
        if (p == par[p]) return p;
        
        return par[p] = parent(par[p], par);
    }
	public static int minimumSpanningTree(ArrayList<ArrayList<Integer>> edges, int n) {
		int[] size = new int[n];
        int[] par = new int[n];
        Arrays.fill(size,1);
        for (int i=0;i<n;i++) {
            par[i]=i;
        }

		Collections.sort(edges, (list1, list2) -> Integer.compare(list1.get(2), list2.get(2)));
		
		int i=0;
		int weight = 0;
		int count =0;
		while(i<n && count < n-1) {// as soon as count =n-1 return
			int u = edges.get(i).get(0);
			int v = edges.get(i).get(1);
			int wt = edges.get(i).get(2);
			int pu = parent(u, par);
			int pv = parent(v, par);
			if (pu != pv) {  
				if (size[pu] < size[pv]) {
					size[pv] += size[pu];
					par[pu] = pv;
				} else {
					size[pu] += size[pv];
					par[pv] = pu;
				}
				weight += wt;
				count++;
			}
			i++;
		}
		return weight;
	}
}
