
class Solution {
public:
    int length(ListNode* head){
        ListNode* temp=head;
        int i=0;
        while(temp){
            temp=temp->next;
            i++;
        }
        return i;
    }
    int pairSum(ListNode* head) {
        if(head==nullptr) return 0;
        int len=length(head);
        ListNode* prev=head;
        for(int i=0;i<len/2;i++){
            prev=prev->next;

        }
        ListNode* curr=prev;
        ListNode* pre=nullptr;
        while(curr){
            ListNode* newNode=curr->next;
            curr->next=pre;
            pre=curr;
            curr=newNode;
        }
       
        ListNode* first = head;
        ListNode* second = pre;
        int sum=0;
        while(second){
            int maxi=second->val+first->val;
            sum=max(maxi,sum);
            second=second->next;
            first=first->next;

        }
        return sum;
        
    }
};