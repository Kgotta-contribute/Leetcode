#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossibleAllocation(vector<int>& arr, int n, int m, int pages) 
{
    int students = 1;   //(initially one student)
    int curr_pages = 0; //(no pages allocated yet)

    for (int i = 0; i < n; i++) 
    {
        if (arr[i] > pages) 
        {
            return false;
        }

        if (curr_pages + arr[i] > pages) 
        {
            students++;
            curr_pages = arr[i];

            if (students > m) 
            {
                return false;
            }
        } 
        else 
        {
            curr_pages += arr[i];
        }
    }

    return true;
}

int allocateBooks(vector<int>& arr, int n, int m) 
{
    // m is num of students & n is num of books
    if (n < m) 
    {
        return -1;
    }

    int total_pages = 0;
    int max_pages = 0;

    for (int i = 0; i < n; i++) 
    {
        total_pages += arr[i];
        max_pages = max(max_pages, arr[i]);
    }

    int left = max_pages;
    int right = total_pages;
    int result = -1;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (isPossibleAllocation(arr, n, m, mid)) 
        {
            result = mid;
            right = mid - 1;
        } 
        else 
        {
            left = mid + 1;
        }
    }

    return result;
}

int main() 
{
    int n, m;
    cout << "Enter the number of books: ";//4
    cin >> n;
    cout << "Enter the number of students: ";//2
    cin >> m;

    vector<int> arr(n);
    cout << "Enter the number of pages in each book: "; //12,34,67,90
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    int result = allocateBooks(arr, n, m);
    cout << "Result: " << result << endl;

    return 0;
}