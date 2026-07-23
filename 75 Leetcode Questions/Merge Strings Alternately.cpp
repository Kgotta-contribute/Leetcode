// QUES -> https://leetcode.com/problems/merge-strings-alternately/description/?envType=study-plan-v2&envId=leetcode-75

// PYTHON :

class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        result = []
        i = j = 0
        len1, len2 = len(word1), len(word2)
        
        while i < len1 and j < len2:
            result.append(word1[i])
            result.append(word2[j])
            i += 1
            j += 1
        
        # Append whichever string has leftovers
        result.append(word1[i:])
        result.append(word2[j:])
        
        return ''.join(result)


// JAVA :

class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder result = new StringBuilder(word1.length() + word2.length());
        int i = 0, j = 0;
        int len1 = word1.length(), len2 = word2.length();

        while (i < len1 && j < len2) {
            result.append(word1.charAt(i));
            result.append(word2.charAt(j));
            i++;
            j++;
        }

        // Append whichever string has leftovers
        if (i < len1) {
            result.append(word1, i, len1);
        }
        if (j < len2) {
            result.append(word2, j, len2);
        }

        return result.toString();
    }
}