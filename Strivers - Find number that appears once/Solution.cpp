#include<bits/stdc++.h>
#include <map>
using namespace std;
//The count of each element is incremented in the map m. 
//If an element appears more than once, its count will be greater than 1.
int find_single_number(int arr[], int n) 
{
  map<int, int> m;  // 'm' is a map object that stores key-value pairs
  //After the first loop, the map m contains a count of each element in the array.
  for (int i = 0; i < n; i++) 
  {
    m[arr[i]]++;
  }
  //In the second for loop, the map m is iterated using an iterator (it). The iterator starts from the beginning of the map 
  //(m.begin()) and stops when it reaches the end of the map (m.end())
  for (auto it = m.begin(); it != m.end(); it++) {
    if (it->second == 1) //Inside the loop, it checks if the count of the current element (it->second) is equal to 1.
    {
      return it->first;
    }
  }
  return -1;
}
int main() 
{
  int arr[] = {6, 6, 1, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int single_number = find_single_number(arr, n);
  cout << "The single number is: " << single_number << endl;
  return 0;
}


/*
 If the key arr[i] already exists in the map, it returns a reference to its corresponding value. 
 If the key doesn't exist, a new entry is created with a default value (in this case, 0) and a reference to that value is returned.
*/