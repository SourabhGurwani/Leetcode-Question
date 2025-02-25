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
    ListNode* middleNode(ListNode* head) {
       ListNode* temp=head;
       int len=1;
       while(temp!=nullptr){
        len++;
        temp=temp->next;

       }
       ListNode* dummy=head;
       if(len%2==0){
        for(int i=1;i<len/2;i++){
            dummy=dummy->next;
        }
       }
       else{
        for(int i=0;i<len/2;i++){
            dummy=dummy->next;
        }
       }
       return dummy;
        
    }

};