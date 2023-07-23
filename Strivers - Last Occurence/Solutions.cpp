#include<bits/stdc++.h>
#include <iostream>
#include <vector>
int lastOccurrence(std::vector<int>& arr, int target) 
{
    int n = arr.size();
    int left = 0;
    int right = n - 1;
    int lastOccur = -1;
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) 
        {
            lastOccur = mid;
            left = mid + 1; // Continue searching to the right for the last occurrence
        } 
        else if (arr[mid] > target) 
        {
            right = mid - 1;
        } 
        else 
        {
            left = mid + 1;
        }
    }

    return lastOccur;
}
int main() 
{
    std::vector<int> arr = {3, 4, 13, 13, 13, 20, 40};
    int target = 13;
    int result = lastOccurrence(arr, target);
    if (result == -1) 
    {
        std::cout << "Target value " << target << " is not present in the array.\n";
    } 
    else 
    {
        std::cout << "The index of the last occurrence of target " << target << " is: " << result << "\n";
    }
    return 0;
}
// #include<bits/stdc++.h>

// using namespace std;

// int solve(int n, int key, vector < int > & v) {
//   int start = 0;
//   int end = n - 1;
//   int res = -1;

//   while (start <= end) {
//     int mid = start + (end - start) / 2;
//     if (v[mid] == key) {
//       res = mid;
//       start = mid + 1;

//     } else if (key < v[mid]) {
//       end = mid - 1;
//     } else {
//       start = mid + 1;
//     }
//   }
//   return res;
// }

// int main() {
//   int n = 7;
//   int key = 13;
//   vector < int > v = {3,4,13,13,13,20,40};
  
//   // returning the last occurrence index if the element is present otherwise -1
//   cout << solve(n, key, v) << "\n";

//   return 0;
// }