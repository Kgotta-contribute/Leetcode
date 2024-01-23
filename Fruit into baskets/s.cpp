// lil complx
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxFruits = 0;
        int lastFruit = -1;
        int secondLastFruit = -1;
        int lastFruitCount = 0;
        int currentCount = 0;

        for (int fruit : fruits) {
            if (fruit == lastFruit || fruit == secondLastFruit) {
                currentCount++;
            } else {
                currentCount = lastFruitCount + 1;
            }

            if (fruit == lastFruit) {
                lastFruitCount++;
            } else {
                lastFruitCount = 1;
                secondLastFruit = lastFruit;
                lastFruit = fruit;
            }

            maxFruits = max(maxFruits, currentCount);
        }

        return maxFruits;
    }
};