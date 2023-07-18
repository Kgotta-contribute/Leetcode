#include <iostream>
//which provides the std::vector container to store a dynamic array.
#include <vector>
//provides the std::unordered_set container to store a collection of unique elements with constant-time average lookup.
#include <unordered_set>

int longestConSequence(const std::vector<int>& nums) {
    int n = nums.size();
    if (n <= 1)
        return n;
    //creates an unordered set numSet and initializes it with the elements of the input vector nums.
    std::unordered_set<int> numSet(nums.begin(), nums.end());
    int maxLen = 0;

    // iterates over each element num in the vector nums. The loop will execute once for each element present in the vector.
    for (int num : nums) {
        // Check if the current number is the start of a sequence (i.e., num-1 is not present in the set)
        //If num - 1 is not found (i.e., it is not present in the set), it means that the current number is the start of a new sequence. 
        //If num - 1 is found in the set, it implies that the current number is part of an existing sequence, and we skip processing it further as it is not the start of a new sequence.
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentLen = 1;

            // Find the length of the con sequence starting from the current number
            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                currentLen++;
            }

            maxLen = std::max(maxLen, currentLen);
        }
    }

    return maxLen;
}

int main() {
    std::vector<int> nums1 = {7,8,9,10,11,100, 200, 1, 3, 2, 4,5,6};
    std::cout << "Example 1: " << longestConSequence(nums1) << std::endl;

    std::vector<int> nums2 = {3, 8, 5, 7, 6};
    std::cout << "Example 2: " << longestConSequence(nums2) << std::endl;

    return 0;
}


/*



#include<bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int> nums) {
        if(nums.size() == 0 ){
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        
        int ans = 1;
        int prev = nums[0];
        int cur = 1;
        
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == prev+1){
                cur++;
            }
            else if(nums[i] != prev){
                cur = 1;
            }
            prev = nums[i];
            ans = max(ans, cur);
        }
        return ans;
    }
    int main()
    {
        vector<int> arr{100,200,1,2,3,4};
        int lon=longestConsecutive(arr);
        cout<<"The longest consecutive sequence is "<<lon<<endl;
        
    }

*/