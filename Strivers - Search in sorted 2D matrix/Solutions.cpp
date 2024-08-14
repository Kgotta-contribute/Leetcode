#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int left = 0, right = rows * cols - 1;
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        int midVal = matrix[mid / cols][mid % cols];
        if (midVal == target)
            return true;
        else if (midVal < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter the elements of the matrix row-wise:\n";
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cin >> matrix[i][j];
        }
    }
    int target;
    cout << "Enter the target integer: ";
    cin >> target;
    bool found = searchMatrix(matrix, target);
    cout << "Output: " << (found ? "true" : "false") << endl;
    return 0;
}




// java
import java.util.Scanner;

public class MatrixSearch {

    public static boolean searchMatrix(int[][] matrix, int target) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        int left = 0, right = rows * cols - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midVal = matrix[mid / cols][mid % cols];
            
            if (midVal == target) {
                return true;
            } else if (midVal < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of rows and columns: ");
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        
        int[][] matrix = new int[rows][cols];
        
        System.out.println("Enter the elements of the matrix row-wise:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        
        System.out.print("Enter the target integer: ");
        int target = scanner.nextInt();
        
        boolean found = searchMatrix(matrix, target);
        System.out.println("Output: " + (found ? "true" : "false"));
        
        scanner.close();
    }
}





// python

def search_matrix(matrix, target):
    if not matrix or not matrix[0]:
        return False

    rows = len(matrix)
    cols = len(matrix[0])
    left, right = 0, rows * cols - 1

    while left <= right:
        mid = (left + right) // 2
        mid_val = matrix[mid // cols][mid % cols]
        
        if mid_val == target:
            return True
        elif mid_val < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return False

def main():
    rows = int(input("Enter the number of rows: "))
    cols = int(input("Enter the number of columns: "))
    
    matrix = []
    print("Enter the elements of the matrix row-wise:")
    for _ in range(rows):
        row = list(map(int, input().split()))
        matrix.append(row)
    
    target = int(input("Enter the target integer: "))
    
    found = search_matrix(matrix, target)
    print("Output:", "true" if found else "false")

if __name__ == "__main__":
    main()
