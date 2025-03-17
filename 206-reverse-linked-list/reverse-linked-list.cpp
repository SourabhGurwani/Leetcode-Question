
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* newnode=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newnode;

        
    }
};