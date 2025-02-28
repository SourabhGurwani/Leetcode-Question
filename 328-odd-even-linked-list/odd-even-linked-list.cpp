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
    ListNode* oddEvenList(ListNode* head) {
         if (head == nullptr || head->next == nullptr) {
        return head; // Nothing to do if the list is empty or has only one node
    }
        ListNode* odd=head;
        ListNode* oddh=odd;
        ListNode* even=odd->next;
        ListNode* evenh=even;
        while(even!=nullptr && even->next!=nullptr){
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }
        odd->next=evenh;
        return oddh;
        
    }
};