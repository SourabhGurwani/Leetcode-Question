
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        int len1=0;
        int len2=0;

        while(temp1!=NULL){
            len1++;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            len2++;
            temp2=temp2->next;
        }
        temp1=headA;
        temp2=headB;
         for(int i=1;i<=abs(len1-len2);i++){
                if(len1>len2){
                temp1=temp1->next;
                }
                else temp2=temp2->next;
            }
        
        while(temp2!=NULL){
            if(temp1==temp2)return temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        return NULL;
        

        
    }
};