#include <iostream>
#include <string>
#include <unordered_map>

bool isAnagram(const std::string& s, const std::string& t) 
{
    if (s.length() != t.length()) 
    {
        return false;
    }

    std::unordered_map<char, int> charCount;

    for (char c : s) 
    {
        charCount[c]++;
    }

    for (char c : t) 
    {
        if (charCount.find(c) == charCount.end() || charCount[c] == 0) 
        {
            return false;
        }
        charCount[c]--;
    }

    return true;
}
int main() 
{
    std::string s1 = "anagram";
    std::string t1 = "nagaram";

    std::string s2 = "rat";
    std::string t2 = "car";

    if (isAnagram(s1, t1)) 
    {
        std::cout << "Output for Example 1: true" << std::endl;
    } 
    else 
    {
        std::cout << "Output for Example 1: false" << std::endl;
    }

    if (isAnagram(s2, t2)) 
    {
        std::cout << "Output for Example 2: true" << std::endl;
    } 
    else 
    {
        std::cout << "Output for Example 2: false" << std::endl;
    }

    return 0;
}
