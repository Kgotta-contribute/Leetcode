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


///////////////////////////// JAVA //////////////////////////////////

import java.util.*;
class Solution {
    public static int missingNumber(vector<Integer> a, int N) {
        int arrSum = 0;
        int totSum = (N * (N + 1)) / 2;
        for (int i = 0; i < N; i++) {
            arrSum += a.get(i);
        }
        return totSum - arrSum;
    }
  
    public static void main(String args[]) {
        Vector<Integer> a = new Vector<Integer>(Arrays.asList(1, 2, 3, 4, 5, 6, 8, 9));
        int n = a.size() + 1;
        int missNum = missingNumber(a, n);
        System.out.println("The missing number is: " + missNum);
    }
}
