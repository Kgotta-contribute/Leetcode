/*
"Given a list of orders with their respective distances and the number of monitors available, 
how can we determine the maximum total number of orders that can be fulfilled while minimizing 
the shipping time?"
*/

#include <iostream>
#include <vector>
#include <algorithm>

int solution(vector<int> &D, vector<int> &C, int P) {
    int totalOrdersFulfilled = 0;
    vector<pair<int, int>> orders;

    for (int i = 0; i < D.size(); i++) {
        orders.push_back(make_pair(D[i], C[i]));
    }

    sort(orders.begin(), orders.end());

    for (int i = 0; i < orders.size(); i++) {
        if (P >= orders[i].second) {
            P -= orders[i].second;
            totalOrdersFulfilled++;
        } else {
            break;
        }
    }

    return totalOrdersFulfilled;
}

int main() {
    vector<int> D = {5, 11, 1, 3};
    vector<int> C = {6, 1, 3, 2};
    int P = 7;

    cout << solution(D, C, P) << endl;

    return 0;
}
