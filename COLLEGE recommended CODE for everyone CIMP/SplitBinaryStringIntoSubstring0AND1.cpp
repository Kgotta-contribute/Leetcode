#include<bits/stdc++.h>
using namespace std;

int maxSubStr(string str, int n)
{
    int cnt0 = 0, cnt1 = 0, cnt = 0;
    for(int i=0; i<n; i++)
    {
        if(str[i] == '0')
        {
            cnt0++;
        }
        else
        {
            cnt++;
        }
        if(cnt0 != cnt1)
        {
            return -1;
        }
        return cnt;
    }
}