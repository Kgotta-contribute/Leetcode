#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || k == 0)
        return head;
    
    int length = 1;
    ListNode *tail = head;
    
    while (tail->next) {
        length++;
        tail = tail->next;
    }
    
    k = k % length;
    if (k == 0)
        return head;
    
    ListNode *newTail = head;
    for (int i = 0; i < length - k - 1; i++) {
        newTail = newTail->next;
    }
    
    ListNode *newHead = newTail->next;
    newTail->next = NULL;
    tail->next = head;
    
    return newHead;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create the linked list
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    int k = 4;
    
    // Rotate the linked list
    ListNode *rotatedHead = rotateRight(head, k);
    
    // Print the rotated linked list
    printList(rotatedHead);
    
    return 0;
}
