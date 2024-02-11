#include <bits/stdc++.h>
using namespace std;

int traffic(int n, int m, vector<int> vehicle) {
    int left = 0, right = 0, count = 0, max_len = 0;
    while(right < n){
        if(vehicle[right] == 0)
            count++;
        while(count > m){ // If number of flips exceeds m, move the left pointer
            if(vehicle[left] == 0)
                count--;
            left++;
        }
        max_len = max(max_len, right - left + 1); // Update max length of consecutive vehicles
        right++;
    }
    return max_len;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> vehicle(n);
    for(int i=0; i<n; i++)
        cin >> vehicle[i];
    cout << traffic(n, m, vehicle) << endl;
    return 0;
}