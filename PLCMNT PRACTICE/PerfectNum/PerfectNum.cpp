#include<bits/stdc++.h>
#include<iostream>
using namespace std;


// Here if the sum of all divisors is equal to the original number then the number is a perfect Number

bool isPerfectN(int num)
{
    int sum = 0;
    for(int i=1; i<=num/2; i++)
    {
        if(num % i == 0)
        {
            sum += i;
        }
    }
    return sum == num;
}
int main()
{
    int num;

    cout<<"\nEnter a num: ";
    cin >> num;

    if(isPerfectN(num))
    {
        cout<<"Its perfect";
    }
    else
    {
        cout<<"Its not perfect";
    }

    return 0;
}
