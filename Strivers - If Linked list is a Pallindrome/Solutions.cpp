#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr;
    ListNode *current = head;
    while (current != nullptr) {
        ListNode *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return true; // An empty list or a single node is considered a palindrome
    }

    ListNode *slow = head;
    ListNode *fast = head;

    // Use slow and fast pointers to find the middle node of the linked list
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // If the number of nodes is odd, move slow one step further to skip the middle node
    if (fast != nullptr) {
        slow = slow->next;
    }

    // Reverse the second half of the linked list
    ListNode *reversedSecondHalf = reverseList(slow);

    // Compare the first half and the reversed second half of the linked list
    ListNode *temp = head;
    while (reversedSecondHalf != nullptr) {
        if (temp->val != reversedSecondHalf->val) {
            return false; // Not a palindrome
        }
        temp = temp->next;
        reversedSecondHalf = reversedSecondHalf->next;
    }

    return true; // Linked list is a palindrome
}

int main() {
    // Test Example 1: [1,2,2,1]
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(2);
    head1->next->next->next = new ListNode(1);

    cout << "Example 1: " << (isPalindrome(head1) ? "true" : "false") << endl;

    // Test Example 2: [1,2]
    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);

    cout << "Example 2: " << (isPalindrome(head2) ? "true" : "false") << endl;

    // Clean up memory
    ListNode *temp;
    while (head1 != nullptr) {
        temp = head1;
        head1 = head1->next;
        delete temp;
    }

    while (head2 != nullptr) {
        temp = head2;
        head2 = head2->next;
        delete temp;
    }

    return 0;
}
