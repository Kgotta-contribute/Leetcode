#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>&a, int N) 
{
    int arrSum = 0;
    int TotalSum = (N*(N+1))/2;
    for(int i=0; i<N-1; i++)
    {
        arrSum += a[i];
    }
    int missingNum = TotalSum - arrSum;
    return missingNum;
}
int main()
{
    int N = 9;
    vector<int> a = {1,2,3,4,5,6,8,9};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}
