
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //Declares a vector named result of size 2, initialized with zeros. 
        //This vector will store the result, where result[0] represents the 
        //duplicate number, and result[1] represents the missing number.
        vector<int> result(2, 0);

        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != nums[nums[i] - 1]) {
                // Swap the elements to their correct positions
                //This ensures that the array becomes sorted with respect to element values.
                //Input: [1, 2, 2, 4]
                //After sorting: [1, 2, 4, 2]
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                //Duplicate found: nums[2] = 4 (result[0] = 4)
                //Missing number: i + 1 = 3 (result[1] = 3)

                // If the element is not in its correct position, it is the duplicate
                result[0] = nums[i];
                // The missing number is at index i + 1
                result[1] = i + 1;
                break;
            }
        }

        return result;
    }
};
