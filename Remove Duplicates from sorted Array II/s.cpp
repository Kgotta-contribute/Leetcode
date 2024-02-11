#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size(); // No duplicates to remove or only one unique element
        }

        int k = 2; // Initialize the result length with the first two elements
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] != nums[k - 1] || nums[i] != nums[k - 2]) {
                nums[k++] = nums[i];
            }
        }

        return k;
    }
};

/*
#include <iostream>
using namespace std;

int main() {
  int nums[] = {0, 0, 1, 1, 1, 1, 2, 3, 3};
  int n = sizeof(nums)/sizeof(nums[0]);
  if (n <= 2) {
    cout << n << ", nums = [";
    for (int i = 0; i < n; ++i) {
      cout << nums[i];
      if (i != n - 1) {
        cout << ",";
      }
    }
    cout << "]" << endl;
    return 0;
  }

  int k = 2;
  for (int i = 2; i < n; ++i) {
    if (nums[i] != nums[k - 1] || nums[i] != nums[k - 2]) {
      nums[k++] = nums[i];
    }
  }

  cout << k << ", nums = [";
  for (int i = 0; i < k; ++i) {
    cout << nums[i];
    if (i != k - 1) {
      cout << ",";
    }
  }
  cout << ",_]" << endl;
  return 0;
}
*/