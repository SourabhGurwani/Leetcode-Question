
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        if(len==n){
            head=head->next;
            return head;
        }
        temp=head;
        int m= len-n+1;
        for(int i=1;i<m-1;i++){
            temp=temp->next;
        }
        temp->next = temp->next->next;
        return head;

   
        
    }
};