#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map<char, int> charCount;
        
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
            //If the count is greater than 0, it means that the character c is available in //the magazine string. In this case, the code decrements the count of character c in the //charCount map to indicate that it has been used.
            else 
            {
                return false;
            }
            //If the count is not greater than 0, it means that the character c is not //available in sufficient quantity in the magazine string to construct the ransom note. In this //case, the code immediately returns false to indicate that the ransom note cannot be //constructed.
        }
        //indicating it can be constructed
        return true;
    }
};

int main() {
    std::string ransomNote = "aa";
    std::string magazine = "aab";
    
    Solution solution;
    bool canConstruct = solution.canConstruct(ransomNote, magazine);
    
    std::cout << "Can construct ransom note: " << (canConstruct ? "true" : "false") << std::endl;
    
    return 0;
}
