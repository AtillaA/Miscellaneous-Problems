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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr; // previous node
        ListNode* curr = head;   // traverse the list

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;    // Store the next node
            curr->next = prev;                  // Reverse the 'current' pointer
            prev = curr;                        // Move 'prev' to 'current' node
            curr = nextNode;                    // Move to the next node
        }

        return prev; // prev will be the new head of the reversed list
    }
};
