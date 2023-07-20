#include<bits/stdc++.h>
using namespace std;

void pascalTriangle(int n)
{
    long long ans = 1;
    cout<<ans<<" ";

    for(int i=1; i<n; i++)
    {
        ans = ans * (n-i);
        ans = ans/i;
        cout<<ans << " ";
    }
    cout<<endl;
}
int main()
{
    int n=5;
    pascalTriangle(n);
    return 0;
}
/*
ans = 1(5-1) = 4    ->     ans = 4/1 = 4
ans = 4(5-2) = 12   ->     ans = 12/2 = 6
ans = 6(5-3) = 12   ->     ans = 12/3 = 4
ans = 4(5-4) = 4    ->     ans = 4/4  = 4
*/