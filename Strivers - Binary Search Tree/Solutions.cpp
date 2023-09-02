// Binary Search Trees

// You are given an array 'order' which represents the inorder traversal o a binary searcg tree. Find out if this traversal is valid or not.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 6
// 2 3 5 8 9 10
// Sample Output 1:
// true   
// Explanation Of Sample Output 1:
// In this testcase, ‘order’ = {2, 3, 5, 8, 9, 10} is a valid inorder traversal for the following binary search tree:

//       8
//     /   \
//   3      9
//  / \       \
// 2   5       10
// Sample Input 2:
// 4
// 1 2 1 4
// Sample Output 2:
// false


#include <vector>
#include<bits/stdc++.h>
bool isValidBST(std::vector<int> &order) {
    int n = order.size();
    if (n <= 1) {
        return true; // An empty tree or a single-node tree is always valid.
    }

    // Initialize two pointers.
    int prev = order[0]; // Initialize prev to the first element.
    int i = 1; // Start from the second element.

    while (i < n) {
        if (order[i] <= prev) {
            return false; // If the current element is less than or equal to the previous element, it's not valid.
        }
        prev = order[i]; // Update prev to the current element.
        i++; // Move to the next element.
    }

    return true; // If we reach here, it's a valid BST.
}
int main() {
    std::vector<int> order1 = {2, 3, 5, 8, 9, 10};
    std::vector<int> order2 = {1, 2, 1, 4};
    std::vector<int> order3 = {48, 2};

    bool result1 = isValidBST(order1);
    bool result2 = isValidBST(order2);
    bool result3 = isValidBST(order3);

    std::cout << "Sample Output 1: " << (result1 ? "true" : "false") << std::endl;
    std::cout << "Sample Output 2: " << (result2 ? "true" : "false") << std::endl;
    std::cout << "Sample Output 3: " << (result3 ? "true" : "false") << std::endl;

    return 0;
}


// 1. Initialize `prev` to the first element of `order1`, which is 2.
// 2. Initialize `i` to 1, indicating we start comparing from the second element.
// 3. In the while loop:
//    - In the first iteration (i = 1):
//      - Check if `order[1]` (3) is less than or equal to `prev` (2). It's not, so we continue.
//      - Update `prev` to 3.
//      - Increment `i` to 2.

//    - In the second iteration (i = 2):
//      - Check if `order[2]` (5) is less than or equal to `prev` (3). It's not, so we continue.
//      - Update `prev` to 5.
//      - Increment `i` to 3.

//    - In the third iteration (i = 3):
//      - Check if `order[3]` (8) is less than or equal to `prev` (5). It's not, so we continue.
//      - Update `prev` to 8.
//      - Increment `i` to 4.

//    - In the fourth iteration (i = 4):
//      - Check if `order[4]` (9) is less than or equal to `prev` (8). It's not, so we continue.
//      - Update `prev` to 9.
//      - Increment `i` to 5.

//    - In the fifth iteration (i = 5):
//      - Check if `order[5]` (10) is less than or equal to `prev` (9). It's not, so we continue.
//      - Update `prev` to 10.
//      - Increment `i` to 6.

//    - The loop ends because `i` is now equal to `n`, which is the size of `order1` (6).
// 4. The function returns `true` because the entire traversal is valid, as all elements are in increasing order.












// #include<bits/stdc++.h>
// #include <vector>
// #include <stack>

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// bool isValidBST(std::vector<int> &order) {
//     std::stack<TreeNode*> stack;
//     TreeNode* prev = nullptr; // To keep track of the previous node.

//     for (int val : order) {
//         TreeNode* current = new TreeNode(val);

//         // Check if the current node's value is less than the previous node's value.
//         if (prev && val <= prev->val) {
//             return false;
//         }

//         // Traverse to the right until you find a greater value.
//         while (!stack.empty() && val > stack.top()->val) {
//             prev = stack.top();
//             stack.pop();
//         }

//         // Connect the current node as the right child of the previous node.
//         if (prev) {
//             prev->right = current;
//         }

//         // Push the current node onto the stack.
//         stack.push(current);

//         // Update prev to the current node.
//         prev = current;
//     }

//     return true;
// }
// // The isValidBST function definition and TreeNode struct go here...

// int main() {
//     std::vector<int> order1 = {2, 3, 5, 8, 9, 10};
//     std::vector<int> order2 = {1, 2, 1, 4};

//     bool result1 = isValidBST(order1);
//     bool result2 = isValidBST(order2);

//     std::cout << "Sample Output 1: " << (result1 ? "true" : "false") << std::endl;
//     std::cout << "Sample Output 2: " << (result2 ? "true" : "false") << std::endl;

//     return 0;
// }



// 1. Initialize an empty stack `stack`.
// 2. Initialize `prev` as `nullptr` (there's no previous node yet).
// 3. Start the loop to iterate through the `order` vector.
//    - First iteration (val = 2):
//      - Create a new TreeNode `current` with a value of 2.
//      - Since `prev` is `nullptr`, there's no comparison for this node.
//      - Push `current` onto the stack.
//      - Update `prev` to `current`.

//    - Second iteration (val = 3):
//      - Create a new TreeNode `current` with a value of 3.
//      - Compare `val` (3) with `prev->val` (2). Since 3 is greater than 2, it's valid.
//      - Push `current` onto the stack.
//      - Update `prev` to `current`.

//    - Third iteration (val = 5):
//      - Create a new TreeNode `current` with a value of 5.
//      - Compare `val` (5) with `prev->val` (3). Since 5 is greater than 3, it's valid.
//      - Push `current` onto the stack.
//      - Update `prev` to `current`.

//    - Fourth iteration (val = 8):
//      - Create a new TreeNode `current` with a value of 8.
//      - Compare `val` (8) with `prev->val` (5). Since 8 is greater than 5, it's valid.
//      - Push `current` onto the stack.
//      - Update `prev` to `current`.

//    - Fifth iteration (val = 9):
//      - Create a new TreeNode `current` with a value of 9.
//      - Compare `val` (9) with `prev->val` (8). Since 9 is greater than 8, it's valid.
//      - Push `current` onto the stack.
//      - Update `prev` to `current`.

//    - Sixth iteration (val = 10):
//      - Create a new TreeNode `current` with a value of 10.
//      - Compare `val` (10) with `prev->val` (9). Since 10 is greater than 9, it's valid.
//      - Push `current` onto the stack.
//      - Update `prev` to `current`.

// 4. The loop is complete; all nodes have been processed.
// 5. Return `true` because the entire traversal is valid.

// So, for the input `{2, 3, 5, 8, 9, 10}`, the code successfully constructs a binary search tree and returns `true` because it's a valid inorder traversal of a binary search tree.