// NOT INITIALIZING I=0 CAN PUT YOU & ME IN BIG TROUBLE SO TAKE CARE !

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
class Solution
{
    public: 
        void sortColors(vector<int> &arr)
        {
            int i=0, low = 0, high = arr.size() - 1;
            while(i <= high)
            {
                if(arr[i] == 0) //taking care of 0's first to put in the beginning 
                {
                    swap(arr[i], arr[low]);
                    low ++;
                    i++;
                }
                else if(arr[i] == 2)    //taking care of 2's by putting them in end first
                {
                    swap(arr[i], arr[high]);
                    high --;
                }
                else{   //taking care of putting 1s in the middle
                    i++;
                }
            }
        }
};

int main()
{
    vector<int> arr1 = {0,1,1,0,2,1,0,0,1,2};
    Solution solution1;
    solution1.sortColors(arr1);
    cout<<"Output is: ";
    cout<<"[";
    for(int num : arr1)
    {
        cout<<num<<", ";
    }
    cout<<"]\n";
    return 0;
}



// JAVA

import java.util.Arrays;

class Solution {
    public void sortColors(int[] arr) {
        int i = 0, low = 0, high = arr.length - 1;
        while (i <= high) {
            if (arr[i] == 0) { // Taking care of 0's first to put in the beginning 
                swap(arr, i, low);
                low++;
                i++;
            } else if (arr[i] == 2) { // Taking care of 2's by putting them in end first
                swap(arr, i, high);
                high--;
            } else { // Taking care of putting 1s in the middle
                i++;
            }
        }
    }

    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        int[] arr1 = {0, 1, 1, 0, 2, 1, 0, 0, 1, 2};
        Solution solution1 = new Solution();
        solution1.sortColors(arr1);
        System.out.print("Output is: ");
        System.out.print(Arrays.toString(arr1));
    }
}





// PYTHON

class Solution:
    def sortColors(self, arr):
        i = 0
        low = 0
        high = len(arr) - 1

        while i <= high:
            if arr[i] == 0:  # Taking care of 0's first to put in the beginning
                self.swap(arr, i, low)
                low += 1
                i += 1
            elif arr[i] == 2:  # Taking care of 2's by putting them in end first
                self.swap(arr, i, high)
                high -= 1
            else:  # Taking care of putting 1s in the middle
                i += 1

    def swap(self, arr, i, j):
        arr[i], arr[j] = arr[j], arr[i]  # Swap elements in Python

if __name__ == "__main__":
    arr1 = [0, 1, 1, 0, 2, 1, 0, 0, 1, 2]
    solution1 = Solution()
    solution1.sortColors(arr1)
    print("Output is:", arr1)
