#include <bits/stdc++.h>
using namespace std;
int searchInsert(vector<int>& arr, int x) 
{
    int n = arr.size(); 
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) 
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x) 
        {
            ans = mid;
            high = mid - 1;
        }
        else 
        {
            low = mid + 1; 
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 4, 7};
    int x = 6;
    int ind = searchInsert(arr, x);
    cout << "The index is: " << ind << "\n";
    return 0;
}



// java
public class SearchInsert {

    public static int searchInsert(int[] arr, int x) {
        int low = 0;
        int high = arr.length - 1;
        int ans = arr.length; // Initialize `ans` to the length of the array, which is the default index if `x` is greater than all elements

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 4, 7};
        int x = 6;
        int index = searchInsert(arr, x);
        System.out.println("The index is: " + index);
    }
}



// python 
def search_insert(arr, x):
    low = 0
    high = len(arr) - 1
    ans = len(arr)  # Initialize `ans` to the length of the list, which is the default index if `x` is greater than all elements

    while low <= high:
        mid = (low + high) // 2
        if arr[mid] >= x:
            ans = mid
            high = mid - 1
        else:
            low = mid + 1
    
    return ans

def main():
    arr = [1, 2, 4, 7]
    x = 6
    index = search_insert(arr, x)
    print(f"The index is: {index}")

if __name__ == "__main__":
    main()

