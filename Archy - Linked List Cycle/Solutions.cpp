#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) {
            return false; // If the list is empty or has only one node, there can't be a cycle.
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow != fast) {
            if (!fast || !fast->next) {
                return false; // If fast reaches the end of the list, there is no cycle.
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return true; // If slow and fast meet, there is a cycle.
    }
};

int main() {
    Solution solution;

    // Example 1: A cycle exists at index 1
    ListNode* head1 = new ListNode(3);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);
    head1->next->next->next->next = head1->next; // Cycle point

    std::cout << "Example 1: " << (solution.hasCycle(head1) ? "True" : "False") << std::endl;

    // Example 2: A cycle exists at index 0
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = head2; // Cycle point

    std::cout << "Example 2: " << (solution.hasCycle(head2) ? "True" : "False") << std::endl;

    // Example 3: No cycle
    ListNode* head3 = new ListNode(1);

    std::cout << "Example 3: " << (solution.hasCycle(head3) ? "True" : "False") << std::endl;

    return 0;
}





// Consider the following linked list with a cycle:

// 1 -> 2 -> 3
//      ^    |
//      |    v
//      6 <- 5
// Here's the step-by-step iteration of the hasCycle function:

// Iteration 1:

// head points to the first node with value 1.
// slow is initialized to head, pointing to the same node.
// fast is initialized to head->next, pointing to the second node with value 2.
// Iteration 2:

// slow moves one step to the second node with value 2.
// fast moves two steps to the third node with value 3.
// Iteration 3:

// slow moves one step to the third node with value 3.
// fast moves two steps to the first node with value 1 (cycle entry point).
// Iteration 4:

// slow moves one step to the first node with value 1.
// fast moves two steps to the third node with value 3.
// Iteration 5:

// slow moves one step to the third node with value 3.
// fast moves two steps to the first node with value 1 (cycle entry point).
// Iteration 6:

// slow moves one step to the first node with value 1.
// fast moves two steps to the third node with value 3.
// At this point, both slow and fast have met at the same node (third node with value 3). Since they have met, we conclude that there is a cycle in the linked list, and the hasCycle function returns true.

// This algorithm detects the cycle efficiently by using two pointers, one moving one step at a time (slow) and the other moving two steps at a time (fast). If there is a cycle, the fast pointer will eventually catch up with the slow pointer, as shown in the iterations.