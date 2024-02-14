#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive, negative;
        for (int num : nums) {
            if (num > 0)
                positive.push_back(num);
            else
                negative.push_back(num);
        }
        
        vector<int> result;
        int i = 0, j = 0;
        // Ensure the rearranged array starts with a positive integer
        if (!positive.empty())
            result.push_back(positive[i++]);
        
        // Rearrange array by alternating positive and negative integers
        while (i < positive.size() || j < negative.size()) {
            if (j < negative.size())
                result.push_back(negative[j++]);
            if (i < positive.size())
                result.push_back(positive[i++]);
        }
        
        return result;
    }
};
/*
positive vector: [3, 1, 2]
negative vector: [-2, -5, -4]
Rearrange array:

Start with a positive integer: result = [3]
Alternate positive and negative integers:
Add -2 from the negative vector: result = [3, -2]
Add 1 from the positive vector: result = [3, -2, 1]
Add -5 from the negative vector: result = [3, -2, 1, -5]
Add 2 from the positive vector: result = [3, -2, 1, -5, 2]
Add -4 from the negative vector: result = [3, -2, 1, -5, 2, -4]
*/