//https://takeuforward.org/arrays/count-subarray-sum-equals-k/
// #include<bits/stdc++.h>
// using namespace std;
// int CountNumOfSubarrays(vector<int> arr, int n)
// {

// }
// int main()
// {
//     vector<int> arr = { 1,2,5,6,3,4,7};
//     int n = arr.size();
//     int k = 10;
//     int res = CountNumOfSubarrays(arr,n);
//     cout<<"\nCount of possible number of subarrays is : "<< res << endl;
// }

#include <bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(); // size of the given array.
    int cnt = 0; // Number of subarrays:

    for (int i = 0 ; i < n; i++) { // starting index i
        int sum = 0;
        for (int j = i; j < n; j++) { // ending index j
            // calculate the sum of subarray [i...j]
            // sum of [i..j-1] + arr[j]
            sum += arr[j];

            // Increase the count if sum == k:
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector arr = {1,2,5,6,3,4,7};
    int k = 10;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}


/*
Solution.cpp: In function 'int findAllSubarraysWithGivenSum(std::vector<int>&, int)':
Solution.cpp:24:9: error: missing template arguments before 'mpp'
     map mpp;
         ^~~
Solution.cpp:27:5: error: 'mpp' was not declared in this scope
     mpp[0] = 1; // Setting 0 in the map.
     ^~~
Solution.cpp: In function 'int main()':
Solution.cpp:47:12: error: missing template arguments before 'arr'
     vector arr = {1 ,5 ,4 ,3 ,6 ,8 ,9};
            ^~~
Solution.cpp:49:44: error: 'arr' was not declared in this scope
     int cnt = findAllSubarraysWithGivenSum(arr, k);
                                            ^~~

[Done] exited with code=1 in 0.874 seconds
*/