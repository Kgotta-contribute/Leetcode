class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // Find the ath node and its previous node
        ListNode* prevA = nullptr;
        ListNode* nodeA = list1;
        for (int i = 0; i < a; i++) {
            prevA = nodeA;
            nodeA = nodeA->next;
        }
        
        // Find the bth node and its next node
        ListNode* nodeB = nodeA;
        for (int i = a; i <= b; i++) {
            nodeB = nodeB->next;
        }
        
        // Connect the previous node of ath node to list2, and then list2 to the next node of bth node
        prevA->next = list2;
        ListNode* currNode = list2;
        while (currNode->next != nullptr) {
            currNode = currNode->next;
        }
        currNode->next = nodeB;
        
        return list1;
    }
};