//https://takeuforward.org/data-structure/find-the-majority-element-that-occurs-more-than-n-2-times/
// #include<bits/stdc++.h>
// using namespace std;
// int countMajority(vector<int>& arr)
// {
//     int cnt;
//     int size = arr.size();
//     for(int i = 0; i < size; i++)
//     {
//         int cnt =0 ;
//         for(int j=0; j<size; j++)
//         {
//             if(arr[i] == arr[j])
//             {
//                 cnt++;
//             }
//         }
//         if(cnt>(size/2)) 
//             return arr[i];    
//     }
//     return -1;
    
// }
// int main()
// {
//     vector<int> arr = {5,1,2,5,2,1,1,5,5,5,5};
//     // int size = arr.size();
//     int res = countMajority(arr);
//     cout<<"\t"<<res<<endl;
//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v) 
{
    int n = v.size();
    map<int,int> m;
    for(int i = 0; i < n; i++)
    {
        m[v[i]]++;
    }
    for(auto it : m)
    {
        if(it.second > (n/2))
        {
            return it.first;
        }
    }
    return -1;
    //it.first refers to the key of the current key-value pair in the map.
    //it.second refers to the value of the current key-value pair in the map. 
}

int main()
{
    vector<int> arr = {5,1,2,5,2,1,1,5,5,5,5};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}

/*
arr = {2, 2, 1, 1, 1, 2, 2}:

The map mpp will store the following key-value pairs:
{1, 3}, {2, 4}

The loop iterates through the map:

First iteration (it = {1, 3}): The count 3 is not greater than (7 / 2), so it doesn't return 1.
Second iteration (it = {2, 4}): The count 4 is greater than (7 / 2), so it returns 2 as the majority element.
The output of this code will be: "The majority element is: 2"


First iteration (it = {1, 3}):

it.first is 1, which represents the first key in the map, i.e., the element 1.
it.second is 3, which represents the count of occurrences of 1 in the vector arr.
Since 3 is not greater than (7 / 2), the condition it.second > (n / 2) evaluates to false, and we move to the next iteration.

Second iteration (it = {2, 4}):

it.first is 2, which represents the second key in the map, i.e., the element 2.
it.second is 4, which represents the count of occurrences of 2 in the vector arr.
Since 4 is greater than (7 / 2), the condition it.second > (n / 2) evaluates to true, and the function immediately returns it.first, which is 2.

*/

