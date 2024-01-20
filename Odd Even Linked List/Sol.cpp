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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            // If the list is empty or has only one node, no rearrangement needed
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even && even->next) {
            // Connect odd nodes
            odd->next = even->next;
            odd = odd->next;

            // Connect even nodes
            even->next = odd->next;
            even = even->next;
        }

        // Append even nodes to the end of odd nodes
        odd->next = evenHead;

        return head;
    }
};
