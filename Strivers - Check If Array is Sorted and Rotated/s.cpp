class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)     // 3 4 5 1 2
        {
            // formula when we rotate an array A then it results into array B
            if (nums[i] > nums[(i + 1) % n])   // A[i] = B[ (i+x) % A.length() ]     
                count++;            // if array is sorted and rotated then it will have only one element which is > than the next one.
            if (count > 1)          // and that exactly is the catch 
                return false;
        }
        return true;
    }
};

-------------------------------------------


```java

class Solution {
    public boolean check(int[] nums) {
        int n = nums.length;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            if (count > 1) {
                return false;
            }
        }
        return true;
    }
}


OR 


// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//   vector<int> nums = {4, 5, 1, 2, 3};    //2 1 3 4
//   int n = nums.size();
//   int count = 0;
//   for (int i = 0; i < n; i++) {
//     if (nums[i] > nums[(i + 1) % n])
//       count++;
//     if (count > 1) {
//       cout << "false\n";
//       return 0;
//     }
//   }
//   cout << "true\n";
//   return 0;
// }  
