// QUESTION -> https://leetcode.com/problems/reverse-vowels-of-a-string/description/?envType=study-plan-v2&envId=leetcode-75

// PYTHON
class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = frozenset('aeiouAEIOU')   # O(1) lookup
        arr = list(s)                       # strings are immutable in Python
        left, right = 0, len(arr) - 1

        while left < right:
            while left < right and arr[left] not in vowels:
                left += 1
            while left < right and arr[right] not in vowels:
                right -= 1
            if left < right:
                arr[left], arr[right] = arr[right], arr[left]
                left += 1
                right -= 1

        return ''.join(arr)










// JAVA
class Solution {
    public String reverseVowels(String s) {
        // arr[left] is a char — in Java, char is a number (its ASCII value). 'a' = 97, 'A' = 65, etc. 
        // So vowels['a'] is literally vowels[97] — a direct memory read. 
        // The entire 128-element array fits in 128 bytes, well within the CPU's L1 cache line. 
        // It's as fast as a lookup can physically get.
        boolean[] vowels = new boolean[128];
        for (char c : "aeiouAEIOU".toCharArray()) {
            vowels[c] = true;           // ASCII index as direct array index
        }

        char[] arr = s.toCharArray();
        int left = 0, right = arr.length - 1;

        while (left < right) {
            while (left < right && !vowels[arr[left]])  left++;
            while (left < right && !vowels[arr[right]]) right--;

            if (left < right) {
                char temp    = arr[left];
                arr[left]    = arr[right];
                arr[right]   = temp;
                left++;
                right--;
            }
        }

        return new String(arr);
    }
}