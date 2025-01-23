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
    
         ListNode* deleteMiddle(ListNode* head) {
        // Edge case: if the list is empty or has only one node
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        // Step 1: Calculate the length of the linked list
        int length = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        // Step 2: Find the index of the middle node
        int mid = length / 2; // 0-based index

        // Step 3: Traverse to the node just before the middle node
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for (int i = 0; i < mid; i++) {
            prev = curr;
            curr = curr->next;
        }

        // Step 4: Delete the middle node
        prev->next = curr->next;
        delete curr;

        return head;
    }
};