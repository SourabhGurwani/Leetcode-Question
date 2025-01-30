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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
           ListNode* dummy = new ListNode(0); // Dummy node to handle edge cases
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer `n+1` steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both fast and slow pointers
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the nth node from end
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return dummy->next; // Return updated head
    }
};