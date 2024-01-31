#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> nums;

    RandomizedSet() {}
    
    bool insert(int val) {
        //if value exists return false
        if(mp.count(val)) return false; 
        //If the value is not present in the set, it is added to the nums vector. 
        nums.push_back(val);
        //Updates the mp to store the index of the newly inserted value in  nums vector. This index is the last index of the vector since we used push_back in the previous step.
        mp[val] = nums.size()-1;
        //Returns true to indicate insertion was successful.
        return true;
    }
    
    bool remove(int val) {
        //If the value is not present, the function returns false because there's nothing to remove.
        if(!mp.count(val)) return false;
        // Retrieves the index of the value to be removed
        int idx = mp[val];
        // Updates the mapping in mp for the value that will be swapped with the value to be removed.
        mp[nums.back()] = idx;
        // Swaps the value to be removed with the last element in the nums vector. 
        swap(nums[idx], nums.back());
        //Removes the last element from the nums vector.
        nums.pop_back();
        // Removes the value from the unordered_map mp since it has been removed from the nums vector.
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
int main() {
    RandomizedSet randomizedSet;
    randomizedSet.insert(1);  // Inserts 1 to nums. mp: {1: 0}, nums: {1}
    randomizedSet.remove(2);  // Value 2 not present, nothing to remove
    randomizedSet.insert(2);  // Inserts 2 to nums. mp: {1: 0, 2: 1}, nums: {1, 2}
    int randomValue = randomizedSet.getRandom();  // Random index: 0 or 1
    randomizedSet.remove(1);  // Removes value 1. mp: {2: 0}, nums: {2}
    randomizedSet.insert(2);  // Value 2 already present, returns false
    int newRandomValue = randomizedSet.getRandom();  // Random index: 0
    return 0;
}