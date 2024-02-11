class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n])
                count++;
            if (count > 1)
                return false;
        }
        return true;
    }
};

/*
#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> nums = {3, 4, 5, 1, 2};
  int n = nums.size();
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] > nums[(i + 1) % n])
      count++;
    if (count > 1) {
      cout << "false\n";
      return 0;
    }
  }
  cout << "true\n";
  return 0;
}
*/