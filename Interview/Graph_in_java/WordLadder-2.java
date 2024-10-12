class Solution {
    public ArrayList<ArrayList<String>> findSequences(String startWord,
                                                      String targetWord,
                                                      String[] wordList) {
        // Create a set of words from the wordList for efficient lookup
        Set<String> words = new HashSet<>(Arrays.asList(wordList));
        
        // Create a queue to store the sequences
        Queue<ArrayList<String>> queue = new LinkedList<>();
        
        // Create the result list
        ArrayList<ArrayList<String>> result = new ArrayList<>();
        
        // Create a list to store words used at each level
        ArrayList<String> usedOnLevel = new ArrayList<>();
        
        // Add the start word to the queue and usedOnLevel
        ArrayList<String> initialSequence = new ArrayList<>();
        initialSequence.add(startWord);
        queue.add(initialSequence);
        usedOnLevel.add(startWord);
        
        int level = 0;
        
        while (!queue.isEmpty()) {
            ArrayList<String> currentSequence = queue.poll();
            String currentWord = currentSequence.get(currentSequence.size() - 1);
            
            // Check if the level has changed
            if (currentSequence.size() > level) {
                level++;
                for (String word : usedOnLevel) {
                    words.remove(word);
                }
                usedOnLevel.clear();
            }
            
            // Check if we've reached the target word
            if (currentWord.equals(targetWord)) {
                result.add(currentSequence);
            }
            
            // Generate new words by changing one character at a time
            for (int i = 0; i < currentWord.length(); i++) {
                char[] wordChars = currentWord.toCharArray();
                for (char c = 'a'; c <= 'z'; c++) {
                    wordChars[i] = c;
                    String newWord = new String(wordChars);
                    
                    if (words.contains(newWord)) {
                        ArrayList<String> newSequence = new ArrayList<>(currentSequence);
                        newSequence.add(newWord);
                        queue.add(newSequence);
                        usedOnLevel.add(newWord);
                    }
                }
            }
        }
        
        return result;
    }
}
