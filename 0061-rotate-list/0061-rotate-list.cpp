
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* tail=head;
        int len=0;
        if(head==NULL)return NULL;
        while(temp->next!=NULL){
            len++;
            tail=tail->next;
            temp=temp->next;
        }
        len++;
        temp=head;
        k=k%len;
        if(k==0)return head;
        for(int i=1;i<len-k;i++){
            temp=temp->next;
        }
        if(k%len!=0){
        tail->next=head;
        head=temp->next;
        temp->next=NULL;
        }
        return head;
       
    }
};