#include <iostream>
#include <unordered_map>
#include <unordered_set>

bool areIsomorphic(const std::string& s, const std::string& t) 
{
    if (s.length() != t.length()) 
    {
        return false;
    }

    std::unordered_map<char, char> charMap;
    std::unordered_set<char> usedChars;

    for (int i = 0; i < s.length(); ++i) 
    {
        char sChar = s[i];
        char tChar = t[i];

        // If the mapping for sChar doesn't exist, create it
        if (charMap.find(sChar) == charMap.end()) 
        {
            // Check if tChar is already mapped to another character
            if (usedChars.find(tChar) != usedChars.end()) 
            {
                return false; // Mapping is not valid
            }
            charMap[sChar] = tChar;
            usedChars.insert(tChar);
        } else {
            // Check if the existing mapping is correct
            if (charMap[sChar] != tChar) 
            {
                return false; // Mapping is not valid
            }
        }
    }

    return true; // All characters can be mapped
}

int main() 
{
    std::string input1_s = "egg";
    std::string input1_t = "add";
    std::cout << "Input1: " << (areIsomorphic(input1_s, input1_t) ? "true" : "false") << std::endl;

    std::string input2_s = "foo";
    std::string input2_t = "bar";
    std::cout << "Input2: " << (areIsomorphic(input2_s, input2_t) ? "true" : "false") << std::endl;

    std::string input3_s = "paper";
    std::string input3_t = "title";
    std::cout << "Input3: " << (areIsomorphic(input3_s, input3_t) ? "true" : "false") << std::endl;

    return 0;
}
