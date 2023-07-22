#include<iostream>
#include<unordered_map>
using namespace std;

int maxLen(int A[], int n) {
    unordered_map<int, int> mpp;
    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];        // keeping track of cumulative sum
        if (sum == 0)
        {
            maxi = i + 1;
        }
        else
        {
            //Here we check if sum value exists in unordered map. The mpp (map) is used to store cumulative sum encountered so far & its corresponding index
            if (mpp.find(sum) != mpp.end())
            {
                //if current sum value exists in mpp, it shows presence of sum b4 & there exists a subarray w '0' sum bw previous occurence of this sum & current index i
                //To calculate length of subarray we calc difference bw current index & index stored in mpp for the same sum ie. i - mpp[sum]
                //We update maxi to max of its current value & this calculated difference
                //This step ensures that we keep track of length of longest subarray with zero sum
                maxi = max(maxi, i - mpp[sum]);
            }
            //If current sum value doesnt exist in the mpp, it means we've not encountered this sum before.So, we add sum to mpp with corresponding index i.
            //This allows us to keep track of 1st occuerence of each sum
            else
            {
                mpp[sum] = i;
            }
        }
    }
    return maxi;


    /*
    //EASY BRUTE FORCE APPROACH
    int maxLen = 0;
    for(int i=0; i<n ;i++)
    {
        int sum = 0;
        for(int j=0; j<n ; j++)
        {
            sum += arr[j];
            if(sum == 0)
                maxLen = max(maxLen, j-i+1);
        }
    }
    return maxLen;
*/
}
int main()
{
    int n1 = 6, n2=8, n3=3, n4=5;
    int A[] = {9,-3,3,-1,6,-5};
    int B[] = {6,-2,2,-8,1,7,4, -10};
    int C[] = {1,0,-5};
    int D[] = {1,3,-5,6,-2};
    cout<<"\nResult : "<<maxLen(A, n1)<<endl;
    cout<<"\nResult : "<<maxLen(B, n2)<<endl;
    cout<<"\nResult : "<<maxLen(C, n3)<<endl;
    cout<<"\nResult : "<<maxLen(D, n4)<<endl;
    return 0;
}
