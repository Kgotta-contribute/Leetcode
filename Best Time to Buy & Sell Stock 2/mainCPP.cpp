#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices) 
{// Input: vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    int maxProfit = 0;
    int minPrice = prices[0];
    for (int i = 1; i < prices.size(); i++) 
    {
        if (prices[i] < minPrice) 
        {
            minPrice = prices[i];
        } 
        else if (maxProfit < prices[i] - minPrice) 
        {
            maxProfit = prices[i] - minPrice;
        }
    }
    return maxProfit;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> prices(n);
    cout << "Enter the stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    int result = maxProfit(prices);
    cout << "Maximum profit: " << result << endl;
    return 0;
}





// JAVA




import java.util.Scanner;
import java.util.Vector;

public class StockProfit {

    public static int maxProfit(Vector<Integer> prices) {
        int maxProfit = 0;
        int minPrice = prices.get(0);
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices.get(i) < minPrice) {
                minPrice = prices.get(i);
            } else if (prices.get(i) - minPrice > maxProfit) {
                maxProfit = prices.get(i) - minPrice;
            }
        }
        return maxProfit;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements in the array: ");
        int n = scanner.nextInt();

        Vector<Integer> prices = new Vector<>(n);

        System.out.print("Enter the stock prices: ");
        for (int i = 0; i < n; i++) {
            prices.add(scanner.nextInt());
        }

        int result = maxProfit(prices);
        System.out.println("Maximum profit: " + result);
    }
}


