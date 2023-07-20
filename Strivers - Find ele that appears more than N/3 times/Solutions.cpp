#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElel(vector<int> v)
{
    int n = v.size();
    vector<int> ls;
    map<int, int> m;
    int mini = int(n/3)+1;
    for(int i=0; i<n; i++)
    {
        m[v[i]]++;
        if(m[v[i]] == mini)
        {
            ls.push_back(v[i]);
        }
        if(ls.size() == 2)
            break;
    }
    return ls;
}
int main()
{
    vector<int> arr = {11,33,33,11,33,11};
    vector<int> ans = majorityElel(arr);
    cout<<"\n Ele are: ";
    for(auto it : ans)
        cout<<it<<" ";
    cout<<"\n";
    return 0;
}