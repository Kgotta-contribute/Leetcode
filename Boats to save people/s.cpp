#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end()); // sort the people by weight
        int left = 0;
        int right = people.size() - 1;
        int count = 0;
        while (left <= right) {
            if (people[left] + people[right] <= limit) { // if a boat can carry two people
                left++;
                right--;
            } else { // if a boat can carry only one person
                right--;
            }
            count++;
        }
        return count;
    }
};

int main() {
    //  1
    vector<int> people1 = {1, 2};
    int limit1 = 3;
    Solution solution1;
    int result1 = solution1.numRescueBoats(people1, limit1);
    cout << " 1 Result: " << result1 << endl;

    //  2
    vector<int> people2 = {3, 2, 2, 1};
    int limit2 = 3;
    Solution solution2;
    int result2 = solution2.numRescueBoats(people2, limit2);
    cout << " 2 Result: " << result2 << endl;

    //  3
    vector<int> people3 = {3, 5, 3, 4};
    int limit3 = 5;
    Solution solution3;
    int result3 = solution3.numRescueBoats(people3, limit3);
    cout << " 3 Result: " << result3 << endl;

    return 0;
}
