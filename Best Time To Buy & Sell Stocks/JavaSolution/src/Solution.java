import java.util.Scanner;

public class Solution 
{
    public static int maxProfit(int[] prices) 
    {
        if (prices.length == 0)
            return 0;

        int minPrice = prices[0];
        int maxProfit = 0;

        for (int price : prices) 					//This starts a loop that iterates over each element price in the prices array.
        {
            minPrice = Math.min(minPrice, price);
            int currentProfit = price - minPrice;
            maxProfit = Math.max(maxProfit, currentProfit);
        }

        return maxProfit;
    }

    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);

        System.out.print("Enter the number of days: ");
        int n = s.nextInt();

        int prices[] = new int[n];
        System.out.println("Enter the stock prices for each day:");
        for (int i = 0; i < n; i++) 
        {
            prices[i] = s.nextInt();
        }

        s.close();

        int maxProfit = maxProfit(prices);
        System.out.println("Maximum Profit: " + maxProfit);
    }
}




