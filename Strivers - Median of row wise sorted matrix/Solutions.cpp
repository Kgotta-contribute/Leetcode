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





