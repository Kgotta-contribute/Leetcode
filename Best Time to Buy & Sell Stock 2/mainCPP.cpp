#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices) {
    int maxProfit = 0;
    int minPrice = prices[0];
    
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }
    
    return maxProfit;
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;
    
    std::vector<int> prices(n);
    std::cout << "Enter the stock prices: ";
    for (int i = 0; i < n; i++) {
        std::cin >> prices[i];
    }
    
    int result = maxProfit(prices);
    std::cout << "Maximum profit: " << result << std::endl;
    
    return 0;
}

