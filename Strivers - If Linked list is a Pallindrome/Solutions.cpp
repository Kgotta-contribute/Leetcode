// TOUGH

/*
we can use the following approach:
1. Find the middle of the linked list using the slow and fast pointer technique.
2. Reverse the second half of the linked list.
3. Compare the first half of the original linked list with the reversed second half.
4. If they match, the linked list is a palindrome. Otherwise, it is not.
*/

#include <iostream>
using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the linked list
        ListNode* temp = nullptr;
        ListNode* curr = slow->next;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = temp;
            temp = curr;
            curr = next;
        }

        // Compare the first half with the reversed second half
        ListNode* p1 = head;
        ListNode* p2 = temp;
        while (p2 != nullptr) {
            if (p1->val != p2->val) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }
};

int main() {
    // Test case 1: [1, 2, 2, 1] -> should return true
    ListNode* head1 = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
    Solution solution1;
    cout << "Test case 1: " << (solution1.isPalindrome(head1) ? "true" : "false") << endl;

    // Test case 2: [1, 2] -> should return false
    ListNode* head2 = new ListNode(1, new ListNode(2));
    Solution solution2;
    cout << "Test case 2: " << (solution2.isPalindrome(head2) ? "true" : "false") << endl;

    // Clean up memory
    delete head1;
    delete head2;

    return 0;
}



////////////////////////// JAVA //////////////////////////////////



class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }

        // Find the middle of the linked list
        ListNode slow = head;
        ListNode fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // Reverse the second half of the linked list
        ListNode temp = null;
        ListNode curr = slow.next;
        while (curr != null) {
            ListNode next = curr.next;
            curr.next = temp;
            temp = curr;
            curr = next;
        }

        // Compare the first half with the reversed second half
        ListNode p1 = head;
        ListNode p2 = temp;
        while (p2 != null) {
            if (p1.val != p2.val) {
                return false;
            }
            p1 = p1.next;
            p2 = p2.next;
        }

        return true;
    }

    public static void main(String[] args) {
        // Test case 1: [1, 2, 2, 1] -> should return true
        ListNode head1 = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
        Solution solution1 = new Solution();
        System.out.println("Test case 1: " + (solution1.isPalindrome(head1) ? "true" : "false"));

        // Test case 2: [1, 2] -> should return false
        ListNode head2 = new ListNode(1, new ListNode(2));
        Solution solution2 = new Solution();
        System.out.println("Test case 2: " + (solution2.isPalindrome(head2) ? "true" : "false"));
    }
}




// #include <iostream>
// using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

// ListNode* reverseList(ListNode* head) {
//     ListNode *prev = nullptr;
//     ListNode *current = head;
//     while (current != nullptr) {
//         ListNode *nextNode = current->next;
//         current->next = prev;
//         prev = current;
//         current = nextNode;
//     }
//     return prev;
// }

// bool isPalindrome(ListNode* head) {
//     if (head == nullptr || head->next == nullptr) {
//         return true; // An empty list or a single node is considered a palindrome
//     }

//     ListNode *slow = head;
//     ListNode *fast = head;

//     // Use slow and fast pointers to find the middle node of the linked list
//     while (fast != nullptr && fast->next != nullptr) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     // If the number of nodes is odd, move slow one step further to skip the middle node
//     if (fast != nullptr) {
//         slow = slow->next;
//     }

//     // Reverse the second half of the linked list
//     ListNode *reversedSecondHalf = reverseList(slow);

//     // Compare the first half and the reversed second half of the linked list
//     ListNode *temp = head;
//     while (reversedSecondHalf != nullptr) {
//         if (temp->val != reversedSecondHalf->val) {
//             return false; // Not a palindrome
//         }
//         temp = temp->next;
//         reversedSecondHalf = reversedSecondHalf->next;
//     }

//     return true; // Linked list is a palindrome
// }

// int main() {
//     // Test Example 1: [1,2,2,1]
//     ListNode *head1 = new ListNode(1);
//     head1->next = new ListNode(2);
//     head1->next->next = new ListNode(2);
//     head1->next->next->next = new ListNode(1);

//     cout << "Example 1: " << (isPalindrome(head1) ? "true" : "false") << endl;

//     // Test Example 2: [1,2]
//     ListNode *head2 = new ListNode(1);
//     head2->next = new ListNode(2);

//     cout << "Example 2: " << (isPalindrome(head2) ? "true" : "false") << endl;

//     // Clean up memory
//     ListNode *temp;
//     while (head1 != nullptr) {
//         temp = head1;
//         head1 = head1->next;
//         delete temp;
//     }

//     while (head2 != nullptr) {
//         temp = head2;
//         head2 = head2->next;
//         delete temp;
//     }

//     return 0;
// }
