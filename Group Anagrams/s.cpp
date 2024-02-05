#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for (const string& str : strs) {
            // Sort each string to identify anagrams
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());

            // Add the original string to the corresponding anagram group
            anagramGroups[sortedStr].push_back(str);
        }
        // Convert the hash map values to the final result
        vector<vector<string>> result;
        for (const auto& group : anagramGroups) {
            result.push_back(group.second);
        }

        return result;
    }
};