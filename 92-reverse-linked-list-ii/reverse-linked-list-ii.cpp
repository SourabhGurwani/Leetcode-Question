
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i=1;
        // ListNode* temp=head;
        if(!head || !head->next){
            return head;
        }
        if(left==right){
            return head;
        }
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* temp=dummy;
        while(i<left){
            temp=temp->next;
            i++;
        }
        ListNode* curr=temp->next;
        // ListNode* newnode=NULL;
        ListNode* prev=NULL; 
        while(i<=right){
            ListNode* newnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=newnode;
            i++;
        }
        temp->next->next=curr;
        temp->next=prev;
        
        return dummy->next;
        
    }
};