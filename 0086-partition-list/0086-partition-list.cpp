
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* low=new ListNode(0);
        ListNode* high=new ListNode(0);

        if(head ==NULL || head->next ==NULL)return head;

        ListNode* temp1=low;
        ListNode* temp2=high;
        while(head !=NULL){
            if(head->val<x){
                temp1->next=head;
                temp1=temp1->next;

            }
            else{
                temp2->next=head;
                temp2=temp2->next;
            }
            head=head->next;
        }
        low=low->next;
        high=high->next;
        if(low==NULL)return high;
        if(high==NULL)return low;
        temp2->next=NULL;

        temp1->next=high;

        return low;

        
        
    }
};