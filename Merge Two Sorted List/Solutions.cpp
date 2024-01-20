#include<iostream>
using namespace std;

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();  // Dummy node for simplifying code
        ListNode* current = dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // the ternary conditional operator (? :) to determine the value of current->next. It is equivalent to an if-else statement. 
        //If list1 is not null, it assigns list1 to current->next; otherwise, it assigns list2.
        current->next = list1 ? list1 : list2;  // Attach remaining nodes

        //This line sets mergedList to the head of the merged list, skipping the dummy node. 
        ListNode* mergedList = dummy->next;  // Head of the merged list
        delete dummy;  // Free memory for the dummy node allocated earlier

        return mergedList;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    //  1
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* mergedList1 = solution.mergeTwoLists(list1, list2);
    cout << "Merged List 1: ";
    printList(mergedList1);

    //  2
    ListNode* list3 = nullptr;
    ListNode* list4 = nullptr;
    ListNode* mergedList2 = solution.mergeTwoLists(list3, list4);
    cout << "Merged List 2: ";
    printList(mergedList2);

    //  3
    ListNode* list5 = nullptr;
    ListNode* list6 = new ListNode(0);
    ListNode* mergedList3 = solution.mergeTwoLists(list5, list6);
    cout << "Merged List 3: ";
    printList(mergedList3);

    return 0;
}



// JAVA



class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int x) {
        val = x;
    }

    ListNode(int x, ListNode next) {
        val = x;
        this.next = next;
    }
}

class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode();  // Dummy node for simplifying code
        ListNode current = dummy;

        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                current.next = list1;
                list1 = list1.next;
            } else {
                current.next = list2;
                list2 = list2.next;
            }
            current = current.next;
        }

        // Use the ternary conditional operator to determine the value of current.next.
        // If list1 is not null, it assigns list1 to current.next; otherwise, it assigns list2.
        current.next = (list1 != null) ? list1 : list2;  

        // This line sets mergedList to the head of the merged list, skipping the dummy node.
        ListNode mergedList = dummy.next;  

        return mergedList;
    }
}

public class Main {
    public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        //  1
        ListNode list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
        ListNode list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
        ListNode mergedList1 = solution.mergeTwoLists(list1, list2);
        System.out.print("Merged List 1: ");
        printList(mergedList1);
    }
}
