#include <iostream>
#include <vector>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size();
    vector<int> result(2, 0);
    
    for (int i = 0; i < n; i++) {
        int num = abs(a[i]);
        if (a[num - 1] > 0) {
            a[num - 1] = -a[num - 1];
        } else {
            result[0] = num;  // Set the repeating number
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            result[1] = i + 1;  // Set the missing number
            break;
        }
    }
    
    return result;
}

int main() {
    vector<int> a = {1, 2, 3, 2};  
    
    vector<int> result = findMissingRepeatingNumbers(a);

    cout << "Repeating number: " << result[0] << endl;
    cout << "Missing number: " << result[1] << endl;

    return 0;
}
