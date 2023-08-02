#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    if (headA == nullptr || headB == nullptr) 
    {
        return nullptr;
    }

    unordered_set<ListNode*> nodes;

    ListNode *tempA = headA;
    while (tempA != nullptr) 
    {
        nodes.insert(tempA);
        tempA = tempA->next;
    }

    ListNode *tempB = headB;
    while (tempB != nullptr) 
    {
        //it is looking for the element pointed to by the pointer tempB in the nodes set.
        //The end() function of the unordered_set returns an iterator that points to the position
        // just after the last element in the set.
        //The find function returns an iterator pointing to the element if it is found in the set. 
        //If the element is not found, it returns the end() iterator. So, this comparison checks if 
        //the current node (tempB) is found in the set (nodes). If it is found, it means the current 
        //node is an intersection node, and the code inside the if block will be executed.
        if (nodes.find(tempB) != nodes.end()) 
        {
            return tempB;
        }
        tempB = tempB->next;
    }

    return nullptr;
}