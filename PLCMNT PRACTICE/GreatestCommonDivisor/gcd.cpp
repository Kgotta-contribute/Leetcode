#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int gcd(int p, int q)
{
    if(p == 0)
        return q;
    if(q == 0)
        return p;
    if(p == q)
        return p;

    if(p>q)
        return gcd(p-q, q);
    else
        return gcd(p, q-p);
}
int main()
{
    int p = 15, q = 8;
    cout<<"GCD of "<<p<<" "<<q<<" is: "<<gcd(p,q);

    return 0;
}
