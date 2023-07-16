#include <iostream>
using namespace std;
int max_consecutive_ones(int prices[], int n) {
  int max_count = 0;
  int current_count = 0;
  for (int i = 0; i < n; i++) 
  {
    if (prices[i] == 1) {
      current_count += 1;
    } else {
      current_count = 0;
    }
    if (current_count > max_count) {
      max_count = current_count;
    }
  }
  return max_count;
}
int main() {
  int prices[] = {1,0,1,1,1,1,1,0,0,0};
  int n = sizeof(prices) / sizeof(prices[0]);
  int max_count = max_consecutive_ones(prices, n);
  cout << "The maximum number of consecutive 1's is: " << max_count << endl;
  return 0;
}
