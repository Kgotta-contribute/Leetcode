//https://takeuforward.org/arrays/find-out-how-many-times-the-array-has-been-rotated/

#include <bits/stdc++.h>
using namespace std;
int findRotationIndex(vector<int> &arr) 
{
    int size = arr.size();
    int minValue = INT_MAX;
    int rotationIndex = -1;
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] < minValue) 
        {
            minValue = arr[i];
            rotationIndex = i;
        }
    }
    return rotationIndex;
}
int main() 
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int rotationCount = findRotationIndex(arr);
    cout << "The array is rotated " << rotationCount << " times.\n";
    return 0;
}