#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> charCount;
        
        // Count the frequency of each character in the magazine
        for (char c : magazine) {
            charCount[c]++;
        }
        
        // Check if the ransomNote can be constructed using the characters from the magazine
        for (char c : ransomNote) 
        {
            if (charCount[c] > 0) 
            {
                charCount[c]--;
            } 
            //If the count is greater than 0, it means that the character c is available in 
            //the magazine string. In this case, the code decrements the count of character c in the 
            //charCount map to indicate that it has been used.
            else 
            {
                return false;
            }
            //If the count is not greater than 0, it means that the character c is not 
            //available in sufficient quantity in the magazine string to construct the ransom note. In this 
            //case, the code immediately returns false to indicate that the ransom note cannot be //constructed.
        }
        //indicating it can be constructed
        return true;
    }
};

int main() {
    string ransomNote = "aa";
    string magazine = "aab";
    
    Solution solution;
    bool canConstruct = solution.canConstruct(ransomNote, magazine);
    
    cout << "Can construct ransom note: " << (canConstruct ? "true" : "false") << endl;
    
    return 0;
}





// JAVA




import java.util.HashMap;

class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        HashMap<Character, Integer> charCount = new HashMap<>();
        
        // Count the frequency of each character in the magazine
        for (char c : magazine.toCharArray()) {
            charCount.put(c, charCount.getOrDefault(c, 0) + 1);
        }
        
        // Check if the ransomNote can be constructed using the characters from the magazine
        for (char c : ransomNote.toCharArray()) {
            if (charCount.containsKey(c) && charCount.get(c) > 0) {
                charCount.put(c, charCount.get(c) - 1);
            } else {
                return false;
            }
        }
        // Indicating it can be constructed
        return true;
    }
}

public class Main {
    public static void main(String[] args) {
        String ransomNote = "aa";
        String magazine = "aab";
        
        Solution solution = new Solution();
        boolean canConstruct = solution.canConstruct(ransomNote, magazine);
        
        System.out.println("Can construct ransom note: " + (canConstruct ? "true" : "false"));
    }
}
