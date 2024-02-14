
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> count;

        // Count the occurrences of each number
        for (int num : nums) {
            count[num]++;
        }

        // Find the number with only one occurrence
        for (auto it = count.begin(); it != count.end(); ++it) {
            if (it->second == 1) {
                return it->first;
            }
        }

        return -1; 
    }
};
