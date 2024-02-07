#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Initialize two dummy nodes for two partitions
        ListNode* beforeHead = new ListNode(0);
        ListNode* afterHead = new ListNode(0);
        
        // Pointers for traversal
        ListNode* before = beforeHead;
        ListNode* after = afterHead;
        
        // Traverse the original list
        while (head != nullptr) {
            // If current node's value is less than x, append it to the before partition
            if (head->val < x) {
                before->next = head;
                before = before->next;
            }
            // If current node's value is greater than or equal to x, append it to the after partition
            else {
                after->next = head;
                after = after->next;
            }
            // Move to the next node in the original list
            head = head->next;
        }
        
        // Connect the two partitions
        after->next = nullptr;
        before->next = afterHead->next;
        
        // Return the head of the modified list
        return beforeHead->next;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    //  1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(2);
    head1->next->next->next->next = new ListNode(5);
    head1->next->next->next->next->next = new ListNode(2);
    
    int x1 = 3;
    
    Solution solution;
    ListNode* result1 = solution.partition(head1, x1);
    
    cout << " 1 Output: ";
    printList(result1);
    
    //  2
    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(1);
    
    int x2 = 2;
    
    ListNode* result2 = solution.partition(head2, x2);
    
    cout << " 2 Output: ";
    printList(result2);
    
    return 0;
}
