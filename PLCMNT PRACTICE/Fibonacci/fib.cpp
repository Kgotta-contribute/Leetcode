#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int fib(int n)
{
    int first = 0, second = 1;
    cout<<"\nFibonacci series upto "<<n<<" terms"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<first<<" ";
        int next = first + second;
        first = second;
        second = next;
    }

    
    // if (n <= 0) {
    //     return 0; // Base case: F(0) = 0
    // } else if (n == 1) {
    //     return 1; // Base case: F(1) = 1
    // } else {
    //     return fib(n - 1) + fib(n - 2);
    // }
    
}
int main()
{
    int n;
    cout<<"\nEnter the number of terms: ";
    cin>>n;

    fib(n);

    // for(int i=0; i<n; i++)
    // {
    // cout<<fib(i)<<" ";
    // }

    return 0;
}
