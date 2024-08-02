/*
The beauty of a string is the difference in frequecies between the most freq & least freq characters

*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int sumOfBeauty(string s) {
    int n = s.length();
    int result = 0;
    
    for (int i = 0; i < n; i++) 
    {
        unordered_map<char, int> freq;
        int mostFreq = 0, leastFreq = n;
        
        for (int j = i; j < n; j++) 
        {
            freq[s[j]]++;
            mostFreq = max(mostFreq, freq[s[j]]);
            leastFreq = min(leastFreq, freq[s[j]]);
            
            result += (mostFreq - leastFreq);
        }
    }
    
    return result;
}

int main() {
    string s1 = "aabcb";
    cout << "Sum of beauty of all substrings: " << sumOfBeauty(s1) << endl;
    
    string s2 = "aabcbaa";
    cout << "Sum of beauty of all substrings: " << sumOfBeauty(s2) << endl;
    
    return 0;
}




// JAVA

import java.util.HashMap;
import java.util.Map;

public class StringBeauty {

    // Method to calculate the sum of beauties of all substrings
    public static int sumOfBeauty(String s) {
        int n = s.length();
        int result = 0;

        for (int i = 0; i < n; i++) {
            // HashMap to store frequency of characters
            Map<Character, Integer> freq = new HashMap<>();
            int mostFreq = 0;
            int leastFreq = n;

            for (int j = i; j < n; j++) {
                char currentChar = s.charAt(j);
                
                // Update frequency count
                freq.put(currentChar, freq.getOrDefault(currentChar, 0) + 1);
                
                // Update mostFreq and leastFreq
                mostFreq = Math.max(mostFreq, freq.get(currentChar));
                leastFreq = Math.min(leastFreq, freq.get(currentChar));

                // Add the difference to the result
                result += (mostFreq - leastFreq);
            }
        }
        
        return result;
    }

    public static void main(String[] args) {
        String s1 = "aabcb";
        System.out.println("Sum of beauty of all substrings: " + sumOfBeauty(s1));
        
        String s2 = "aabcbaa";
        System.out.println("Sum of beauty of all substrings: " + sumOfBeauty(s2));
    }
}





// PYTHON

from collections import defaultdict

def sum_of_beauty(s):
    n = len(s)
    result = 0
    
    for i in range(n):
        freq = defaultdict(int)
        most_freq = 0
        least_freq = n
        
        for j in range(i, n):
            freq[s[j]] += 1
            most_freq = max(most_freq, freq[s[j]])
            least_freq = min(least_freq, freq[s[j]])
            
            result += (most_freq - least_freq)
    
    return result

# Test cases
s1 = "aabcb"
print("Sum of beauty of all substrings:", sum_of_beauty(s1))

s2 = "aabcbaa"
print("Sum of beauty of all substrings:", sum_of_beauty(s2))
