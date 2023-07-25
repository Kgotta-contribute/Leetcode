/*
The code uses binary search to find floor value of given positive num.
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int floorSqrt(int n)
{
    // squarae root of 0 & 1 is equal to itself
    if(n==0 || n==1)
    {
        return n;
    }
    //setting binary search rage bw '1' & 'n' & a variable res to keep track of floor values of sqrt
    int left = 1;
    int right = n;
    int result = 0;

    while(left <= right)
    {
        int mid = left + (right-left)/2;
        //checking if square of mid value is less than or equal to n.
        //if this condition is true then mid value could be a potential candidate for floor value of square root
        if(mid <= n/mid)
        {
            //If mid*mid is less than or equal to n, update the result & search the right half
            result = mid;
            //if square of mid is greater than 'n' -> current mid value is too large & binary search needs to be continued
            //in the left half to find a smaller candidate
            left = mid+1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return result;
}
int main()
{
    int n;
    std::cout<<"\nEnter a positive number ";
    std::cin>>n;

    int result = floorSqrt(n);
    std::cout<<"Result: "<<result<<std::endl;

    return 0;
}
// Time comp - )(log n)
