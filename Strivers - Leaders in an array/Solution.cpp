#include <iostream>
#include <vector>
using namespace std;

void findLeaders(const vector<int>& arr) 
{
    int n = arr.size();
    //maxRight index is initialized with value of rightmost index
    int maxRight = arr[n - 1];
    //will store leaders found in array
    vector<int> leaders;
    //The rightmost element is added to this vector as it is always considered as a leader
    leaders.push_back(maxRight);
    //A reverse loop
    for (int i = n - 2; i >= 0; i--) 
    {
        //if current element(a[2] for eg is 1) is greater than current maximum(max = 0)
        if (arr[i] > maxRight) 
        {
            maxRight = arr[i];
            leaders.push_back(maxRight);
        }
    }
    cout << "Leaders in the array: ";
    for (int i = leaders.size() - 1; i >= 0; i--) 
    {
        cout << leaders[i] << " ";
    }
    cout << endl;
}
int main() 
{
    vector<int> arr1 = {4, 7, 1, 0};
    findLeaders(arr1);
    vector<int> arr2 = {10, 22, 12, 3, 0, 6};
    findLeaders(arr2);

    return 0;
}
