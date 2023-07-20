#include<bits/stdc++.h>
using namespace std;
void printPascalsTriangle(int n)
{
    for(int i=0; i<n; i++)
    {
        int num = 1;
        for(int j=0; j<=i; j++)
        {
            cout<<num<<" ";
            num = num * (i-j) / (j+1);
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    n=5;
    // cout<<"Enter the number of rows(n): ";
    // cin>>n;
    cout<<"Fist "<<n<<" rows of Pascals Triangle \n";
    printPascalsTriangle(n);
    return 0;
}

// OR

/*
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> pascalTriangle(int n)
{
    vector<vector<int>> ans;

    for(int row = 1; row <= n; row++)
    {
        long long val = 1;
        vector<int> ansRow;
        ansRow.push_back(1);

        for(int col = 1; col<row; col++)
        {
            val = val * (row-col);
            val = val / col;
            ansRow.push_back(val);
        }
        ans.push_back(ansRow);
    }
    return ans;
}
int main()
{
    int n;
    cout<<"\nEnter num of rows: ";
    cin>>n;
    vector<vector<int>> ans = pascalTriangle(n);
    cout<<"First "<<n<<" rows of P triangle: ";
    for(auto it: ans)
    {
        for(auto ele : it)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
*/