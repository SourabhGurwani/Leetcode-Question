
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp=head;
        ListNode* slow=head;
        ListNode* fast=head;
        bool flag=false;
        while(fast!=NULL && fast->next !=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                flag=true;
                break;
            }
        }
        if(flag==true){
         while(temp!=slow){
            temp=temp->next;
            slow=slow->next;
         }
         return slow;
        }
        else return NULL;

        
    }
};