#include <iostream>

using namespace std;

Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int length(ListNode* head) 
    {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
    
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (!head || k == 0) return head;
        
        int len = length(head);
        // calculates k1 % len = 2 % 5 = 2. So, we need to rotate by 2 positions.
        k %= len; // Reduce k to be less than the length of the list
        
        if (k == 0) return head; // No rotation needed
        
        // Find the (len - k)th node
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < k; i++) {
            fast = fast->next;          // At this point, fast points to node 4, and slow points to node 3.
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Rotate the list
        fast->next = head; // here we are making the list circular : 1 2 3 4 5 1 2 3 4 5 : & from here we take 4 5 1 2 3 ie. 5 pointing to 1
        head = slow->next;  // currently slow->next is at 3; weare making it point to node 4, ie. slow->next ie. making it head node
        slow->next = nullptr; // slow is pointing to 3 & it's next is pointing to null
        
        return head;
    }
};

Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    //  1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    
    int k1 = 2;
    
    ListNode* result1 = solution.rotateRight(head1, k1);
    cout << " 1 Output: ";
    printList(result1);
    
    //  2
    ListNode* head2 = new ListNode(0);
    head2->next = new ListNode(1);
    head2->next->next = new ListNode(2);
    
    int k2 = 4;
    
    ListNode* result2 = solution.rotateRight(head2, k2);
    cout << " 2 Output: ";
    printList(result2);
    
    return 0;
}


