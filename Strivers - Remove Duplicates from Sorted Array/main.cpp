#include<iostream>

using namespace std;
int removeDuplicates(int arr[], int n)
{
  int i = 0;
  for (int j = 1; j < n; j++) 
  {
    if (arr[i] != arr[j]) 
	{
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}
int main() {
  int arr[] = {1,1,2,2,2,3,3,4,4,5,5,6};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}



//#include <vector>
//
//int removeDuplicates(std::vector<int>& nums) {
//    int n = nums.size();
//    if (n <= 1)
//        return n;
//
//    int index = 1;
//    for (int i = 1; i < n; i++) {
//        if (nums[i] != nums[i - 1]) {
//            nums[index] = nums[i];
//            index++;
//        }
//    }
//    return index;
//}
//
//int main() {
//    std::vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 4, 5, 5, 6};
//    
//    int newSize = removeDuplicates(nums);
//
//    std::cout << "After removing duplicates: ";
//    for (int i = 0; i < newSize; i++) 
//	{
//        std::cout << nums[i] << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}

