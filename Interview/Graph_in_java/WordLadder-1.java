class Solution {
    class Pair {
        String str;
        int count;
        Pair(String s, int c) {
            str = s;
            count = c;
        }
    }
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Map<String, Integer> words = new HashMap<>();
        for (var i : wordList) {
            words.put(i,1);
        }
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(beginWord,1));
        int ans = 0;
        while(!q.isEmpty()) {
            Pair p = q.peek();
            String s = p.str;
            int c = p.count;
            if (s.equals(endWord)) {
                ans = c;
            }
            q.poll();
            for (int i=0;i<s.length();i++) {
                for (int j=97;j<=122;j++) {
                    char ch = (char)j;
                    StringBuilder sb = new StringBuilder(s);
                    sb.setCharAt(i,ch);
                    String newS = sb.toString();
                    if (words.containsKey(newS)) {
                        words.remove(newS);
                        q.add(new Pair(newS, c +1));
                    }
                }
            }
        }
        return ans;
    }
}
