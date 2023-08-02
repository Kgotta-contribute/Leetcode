#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // Move fast pointer n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove the nth node from the end
    ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    return dummy->next;
}

// Function to print the linked list
void printLinkedList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Function to delete the entire linked list to prevent memory leaks
void deleteLinkedList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Example usage:
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    std::cout << "Original linked list: ";
    printLinkedList(head);

    head = removeNthFromEnd(head, n);

    std::cout << "Linked list after removal: ";
    printLinkedList(head);

    // Clean up memory by deleting the linked list
    deleteLinkedList(head);

    return 0;
}




// #include <iostream>

// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

// ListNode* removeNthFromEnd(ListNode* head, int n) {
//     ListNode* dummy = new ListNode(0);
//     dummy->next = head;
//     ListNode* fast = dummy;
//     ListNode* slow = dummy;

//     // Move fast pointer n+1 steps ahead
//     for (int i = 0; i <= n; i++) {
//         fast = fast->next;
//     }

//     // Move both pointers until fast reaches the end
//     while (fast) {
//         fast = fast->next;
//         slow = slow->next;
//     }

//     // Remove the nth node from the end
//     ListNode* toDelete = slow->next;
//     slow->next = slow->next->next;
//     delete toDelete;

//     return dummy->next;
// }

// // Function to print the linked list
// void printLinkedList(ListNode* head) {
//     while (head) {
//         std::cout << head->val << " ";
//         head = head->next;
//     }
//     std::cout << std::endl;
// }

// // Example usage:
// int main() {
//     ListNode* head = new ListNode(1);
//     head->next = new ListNode(2);
//     head->next->next = new ListNode(3);
//     head->next->next->next = new ListNode(4);
//     head->next->next->next->next = new ListNode(5);

//     int n = 2;

//     std::cout << "Original linked list: ";
//     printLinkedList(head);

//     head = removeNthFromEnd(head, n);

//     std::cout << "Linked list after removal: ";
//     printLinkedList(head);

//     return 0;
// }
