#include<bits/stdc++.h>
using namespace std;

// return 1, if == m
// return 0, if < m
// return 2, if > m

int func(int mid, int n, int m)
{
    //The func calcs Nth power of a given number 'mid' & copares it with target num 'm'
    long long ans = 1;
    for(int i=1; i<=n; i++)
    {
        // clculating Nth power of mid
        ans = ans * mid;
        //The below indicates that current mid value is too large & we need to search the lower half of search space. 
        //If 'ans' > m , it means Nth power of mid has exceeded target number m so it returns 2.
        if(ans > m) return 2;
    }
    // If loop completes without 'ans' exceeding 'm' it checks if 'ans' is = 'm'. If it is then mid^n = m & it returns 1.
    if(ans == m) return 1;
    return 0;
}
//Performing binary search on the answer space, where range of possible ansers is between 1 & m
int NthRoot(int n, int m)
{
    //Use Binary Search on the answer space
    int low = 1, high = m;
    while(low <= high)
    {
        int mid = (low + high)/2;
        int midN = func(mid, n, m);
        if(midN == 1)
        {
            return mid;
        }
        else if(midN == 0)  //if == 0
            low = mid+1;    // it means we need to search in the upper half so it updates low = mid + 1
        else
            high = mid-1;   // if == 2, it means we need to search in lower hald so high = mid-1;

        //The binary search continues until 'low' becomes greater tahn 'high' meaning search space is empty . If Nth root not found we return -1
    }
    return -1;
}
int main()
{
    int n = 3, m = 27;
    int ans = NthRoot(n,m);
    cout<<"The ans is : "<<ans <<"\n";
    return 0;
}