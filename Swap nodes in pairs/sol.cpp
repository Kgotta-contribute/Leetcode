/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Create a dummy node to simplify the code
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Pointer to keep track of the previous node
        ListNode* prev = dummy;

        while (head && head->next) {
            // Nodes to be swapped
            ListNode* first = head;
            ListNode* second = head->next;

            // Swap the nodes
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // Move to the next pair
            prev = first;
            head = first->next;
        }

        ListNode* result = dummy->next;
        delete dummy;

        return result;
    }
};
