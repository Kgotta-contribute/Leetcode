#include<bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string> &wordDict)
{
    int n = s.size();

    vector<bool> dp(n+1, false);

    dp[0] = true;
    for(int i=1; i<=n; i++)
    {
        for(int j = i-1; j>=0; j--)
        {
            if(dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end())
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}