class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        ListNode *slow = head, *fast = head, *prev = NULL, *next = NULL;

        // Find the middle of the list and reverse the second half
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        // If the list has odd number of nodes, skip the middle node
        if (fast != NULL) {
            slow = slow->next;
        }

        // Compare first half and reversed second half of the list
        while (prev != NULL) {
            if (prev->val != slow->val) {
                return false;
            }
            prev = prev->next;
            slow = slow->next;
        }
return true;
    }
};
