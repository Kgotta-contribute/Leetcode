#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int>>& matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int totalEle = rows * cols;

    int left = INT_MIN, right = INT_MAX;

    while(left<right)
    {
        int mid = left + (right - left)/2;
        int count = 0;

        for(int i=0; i<rows; i++)
        {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        if(count < totalEle / 2 + 1)
        {
            left = mid + 1;
        } 
        else
        {
            right = mid;
        }
    }
    return left;
}
int main()
{
    int r,c;
    cin>>r>>c;

    vector<vector<int>>matrix(r, vector<int>(c));

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>matrix[i][j];
        }
    }

    int median = findMedian(matrix);
    cout<<"Median = "<<median<<endl;

    return 0;
}


/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the median of a row-wise sorted matrix
int findMatrixMedian(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int low = INT_MAX, high = INT_MIN;

    // Find the minimum and maximum elements in the matrix
    for (int i = 0; i < rows; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][cols - 1]);
    }

    int desired = (rows * cols + 1) / 2;

    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;

        // Count the number of elements less than or equal to the middle element
        for (int i = 0; i < rows; i++) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if (count < desired)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter the elements of the matrix row-wise:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int median = findMatrixMedian(matrix);
    cout << "Median of the matrix is: " << median << endl;

    return 0;
}

*/




