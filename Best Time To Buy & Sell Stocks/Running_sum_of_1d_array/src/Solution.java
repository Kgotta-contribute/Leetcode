import java.util.Scanner;

public class Solution {
    public static int[] runningSum(int[] nums) {
        int[] runningSums = new int[nums.length];
        runningSums[0] = nums[0];

        for (int i = 1; i < nums.length; i++) {
            runningSums[i] = runningSums[i - 1] + nums[i];
        }

        return runningSums;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of elements in the array: ");
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        int[] nums = new int[n];
        System.out.print("Enter the array elements: ");
        String input = scanner.nextLine();
        String[] elements = input.split(" ");

        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(elements[i]);
        }

        int[] result = runningSum(nums);

        System.out.print("Running sum: ");
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + " ");
        }
    }
}
