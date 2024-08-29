/*
The beauty of a string is the difference in frequecies between the most freq & least freq characters

*/


// JAVA

import java.util.HashMap;
import java.util.Map;

class Solution {
    public int beautySum(String s) {
        int n = s.length();
        int totalBeauty = 0;

        // Iterate over every possible starting point of a substring
        for (int i = 0; i < n; i++) {
            // Frequency map for the current substring
            Map<Character, Integer> freqMap = new HashMap<>();
            int maxFreq = 0, minFreq = n;

            // Expand the substring from the starting point
            for (int j = i; j < n; j++) {
                char ch = s.charAt(j);
                // Update the frequency map
                freqMap.put(ch, freqMap.getOrDefault(ch, 0) + 1);
                
                // Update max and min frequencies
                maxFreq = Math.max(maxFreq, freqMap.get(ch));
                
                // Update minFreq considering only characters that appear in the substring
                minFreq = n;
                for (int freq : freqMap.values()) {
                    if (freq > 0) {
                        minFreq = Math.min(minFreq, freq);
                    }
                }
                
                // Calculate beauty for the current substring
                totalBeauty += (maxFreq - minFreq);
            }
        }
        
        return totalBeauty;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String s1 = "aabcb";
        System.out.println("Sum of beauty of all substrings: " + sol.beautySum(s1));
        
        String s2 = "aabcbaa";
        System.out.println("Sum of beauty of all substrings: " + sol.beautySum(s2));
    }
}






// CPP
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int totalBeauty = 0;

        // Iterate over every possible starting point of a substring
        for (int i = 0; i < n; ++i) {
            // Frequency map for the current substring
            unordered_map<char, int> freqMap;
            int maxFreq = 0, minFreq = n;

            // Expand the substring from the starting point
            for (int j = i; j < n; ++j) {
                char ch = s[j];
                // Update the frequency map
                freqMap[ch]++;
                
                // Update max and min frequencies
                maxFreq = max(maxFreq, freqMap[ch]);
                
                // Update minFreq considering only characters that appear in the substring
                minFreq = n;
                for (const auto& entry : freqMap) {
                    if (entry.second > 0) {
                        minFreq = min(minFreq, entry.second);
                    }
                }
                
                // Calculate beauty for the current substring
                totalBeauty += (maxFreq - minFreq);
            }
        }
        
        return totalBeauty;
    }
};

// int main() {
//     Solution sol;
//     string s1 = "aabcb";
//     cout << "Sum of beauty of all substrings: " << sol.beautySum(s1) << endl;
    
//     string s2 = "aabcbaa";
//     cout << "Sum of beauty of all substrings: " << sol.beautySum(s2) << endl;
    
//     return 0;
// }





// PYTHON
class Solution(object):
    def beautySum(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        total_beauty = 0
        
        # Iterate over every possible starting point of a substring
        for i in range(n):
            # Frequency dictionary for the current substring
            freq_map = {}
            max_freq = 0
            min_freq = n
            
            # Expand the substring from the starting point
            for j in range(i, n):
                ch = s[j]
                # Update the frequency map
                if ch in freq_map:
                    freq_map[ch] += 1
                else:
                    freq_map[ch] = 1
                
                # Update max and min frequencies
                max_freq = max(max_freq, freq_map[ch])
                
                # Update min_freq considering only characters that appear in the substring
                min_freq = n
                for freq in freq_map.values():
                    if freq > 0:
                        min_freq = min(min_freq, freq)
                
                # Calculate beauty for the current substring
                total_beauty += (max_freq - min_freq)
        
        return total_beauty

# Example usage
if __name__ == "__main__":
    sol = Solution()
    s1 = "aabcb"
    print("Sum of beauty of all substrings:", sol.beautySum(s1))
    
    s2 = "aabcbaa"
    print("Sum of beauty of all substrings:", sol.beautySum(s2))
