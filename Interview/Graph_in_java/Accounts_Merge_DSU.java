class Solution {
    int[] size = new int[1002];
    int[] par = new int[1002];
    int parent(int p) {
        if (p == par[p]) return p;

        return par[p] = parent(par[p]);
    }
    void merge(int a, int b) {
        int pa = parent(a);
        int pb = parent(b);
        if (pa == pb) return;
        if (size[pa]<size[pb]) {
            par[pa] = pb;
            size[pb]+=size[pa];
        } else {
            par[pb] = pa;
            size[pa]+=size[pb];
        }
    }
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        for (int i=0;i<1002;i++) {
            par[i]= i;
            size[i] =1;
        }
        // this map basically stores for each email what is the index node it is attached
        // and if that email is already attached to someone then merge current index i.e node to previous
        HashMap<String, Integer> emailNode = new HashMap<>();
        int n = accounts.size();
        for (int i =0;i<n;i++) {
            for (int j=1;j<accounts.get(i).size();j++) {
                String s = accounts.get(i).get(j);
                if (emailNode.containsKey(s)) {
                    merge(emailNode.get(s), i);
                } else {
                    emailNode.put(s,i);
                }
            }
        }
        //System.out.println(emailNode);
        HashMap<Integer, Set<String> > nodeToEmailMap = new HashMap<>();
        // this map stores node and list of emails conditions are imp
        // if we are node or its parent are not already present then will add new node with list
        for (var entry : emailNode.entrySet()) {
            String s = entry.getKey();
            int node = entry.getValue();
            
            int pa = parent(node);
            nodeToEmailMap.computeIfAbsent(pa, k -> new HashSet<>()).add(s);
        }
        //System.out.println(nodeToEmailMap);
        // Here String back the list with name and sorted emails
        List<List<String>> ans = new ArrayList<>();
        for (var entry : nodeToEmailMap.entrySet()) {
            String key = accounts.get(entry.getKey()).get(0);
            Set<String> val = entry.getValue();
            
            List<String> temp = new ArrayList<>();
            temp.add(key);
            
            temp.addAll(new ArrayList<>(val));
            Collections.sort(temp.subList(1,temp.size()));
            //System.out.println(key + " -> " + temp);
            ans.add(temp);
        }
        return ans;
    }
}
