//  QUESTION -> https://leetcode.com/problems/reverse-words-in-a-string/?envType=study-plan-v2&envId=leetcode-75

// PYTHON :

class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(s.split()[::-1]) # string concatenation -> ' '.join



// JAVA 
class Solution {
    public String reverseWords(String s) {
        int left = 0;
        int right = s.length() - 1;

        // ── Phase 1: trim leading & trailing spaces ──────────────
        while (left <= right && s.charAt(left)  == ' ') left++;
        while (left <= right && s.charAt(right) == ' ') right--;

        StringBuilder result = new StringBuilder();

        // ── Phase 2: walk RIGHT → LEFT, collect words ────────────
        while (right >= left) {

            // skip inter-word spaces (moving left)
            while (right >= left && s.charAt(right) == ' ') right--;

            // mark word END
            int wordEnd = right;

            // find word START
            while (right >= left && s.charAt(right) != ' ') right--;

            // right now sits one before the word → slice [right+1 .. wordEnd]
            if (result.length() > 0) result.append(' ');
            result.append(s, right + 1, wordEnd + 1);  // ← O(word_length), no shift
        }

        return result.toString();
    }
}