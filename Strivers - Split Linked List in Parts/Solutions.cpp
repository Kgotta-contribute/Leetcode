#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Count the length of the linked list
        int length = 0;
        ListNode* current = head;
        while (current) {
            length++;
            current = current->next;
        }
        
        // Calculate the size of each part and the number of extra nodes
        int partSize = length / k;
        int extraNodes = length % k;
        
        vector<ListNode*> result;
        current = head;
        for (int i = 0; i < k; i++) {
            result.push_back(current);
            int partLength = partSize + (extraNodes > 0 ? 1 : 0);
            
            // Move to the end of the current part
            for (int j = 0; j < partLength - 1; j++) {
                if (current)
                    current = current->next;
            }
            
            // If there are extra nodes, move to the next node
            if (current) {
                ListNode* nextNode = current->next;
                current->next = nullptr;
                current = nextNode;
                extraNodes--;
            }
        }
        
        return result;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 3;

    Solution solution;
    std::vector<ListNode*> parts = solution.splitListToParts(head, k);

    // Print each part of the split linked list
    for (int i = 0; i < parts.size(); i++) {
        ListNode* current = parts[i];
        std::cout << "Part " << i + 1 << ": ";
        while (current) {
            std::cout << current->val << " -> ";
            current = current->next;
        }
        std::cout << "null" << std::endl;
    }

    return 0;
}



// The code counts the length of the linked list, which is 5 in this case.
// It calculates partSize as length / k and extraNodes as length % k, which results in partSize = 1 and extraNodes = 2.
// The result vector is initialized to store the split linked list parts.

// The loop for (int i = 0; i < k; i++) starts iterating, where i represents the current part number (0-based).

// Iteration 1 (i=0):

// result.push_back(current) adds the head node to the result vector, and partLength is set to 2 (1 partSize + 1 extra node).

// The loop for (int j = 0; j < partLength - 1; j++) moves the current pointer to the end of the current part. In this case, it moves to node 2.

// The code checks for extra nodes (if (current)), finds an extra node (node 3), and moves to it.

// Iteration 2 (i=1):

// result.push_back(current) adds the node 3 to the result vector, and partLength is set to 1 (1 partSize).

// The loop for (int j = 0; j < partLength - 1; j++) doesn't execute since partLength - 1 is 0, and the current pointer remains at node 4.

// The code checks for extra nodes (if (current)), finds an extra node (node 4), and moves to it.

// Iteration 3 (i=2):

// result.push_back(current) adds the node 4 to the result vector, and partLength is set to 1 (1 partSize).

// The loop for (int j = 0; j < partLength - 1; j++) doesn't execute since partLength - 1 is 0, and the current pointer remains at node 5.

// The code checks for extra nodes (if (current)), finds an extra node (node 5), and moves to it.

// The loop ends (i becomes 3), but no additional iterations occur because i < k is no longer true.

// The function returns the result vector, which contains the split linked list parts.

// In the main function, it prints each part of the split linked list.

// Part 1: 1 -> 2 -> null
// Part 2: 3 -> null
// Part 3: 4 -> 5 -> null







// JAVA

import java.util.ArrayList;
import java.util.List;

class ListNode {
    int val;
    ListNode next;

    ListNode() {
        this.val = 0;
        this.next = null;
    }

    ListNode(int x) {
        this.val = x;
        this.next = null;
    }

    ListNode(int x, ListNode next) {
        this.val = x;
        this.next = next;
    }
}

class Solution {
    public List<ListNode> splitListToParts(ListNode head, int k) {
        // Count the length of the linked list
        int length = 0;
        ListNode current = head;
        while (current != null) {
            length++;
            current = current.next;
        }
        
        // Calculate the size of each part and the number of extra nodes
        int partSize = length / k;
        int extraNodes = length % k;
        
        List<ListNode> result = new ArrayList<>();
        current = head;
        for (int i = 0; i < k; i++) {
            ListNode partHead = current;
            int currentPartSize = partSize + (extraNodes > 0 ? 1 : 0);
            
            // Move to the end of the current part
            for (int j = 0; j < currentPartSize - 1; j++) {
                if (current != null) {
                    current = current.next;
                }
            }
            
            // If there are extra nodes, move to the next node
            if (current != null) {
                ListNode nextNode = current.next;
                current.next = null;
                current = nextNode;
                extraNodes--;
            }
            
            result.add(partHead);
        }
        
        return result;
    }
}

public class Main {
    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        int k = 3;

        Solution solution = new Solution();
        List<ListNode> parts = solution.splitListToParts(head, k);

        // Print each part of the split linked list
        for (int i = 0; i < parts.size(); i++) {
            ListNode current = parts.get(i);
            System.out.print("Part " + (






// PYTHON

