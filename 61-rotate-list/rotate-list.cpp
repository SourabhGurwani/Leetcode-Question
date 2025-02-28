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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        if(k==0){
            return head;
        }
        else{
            int lenght=1;
            ListNode* temp=head;
            while(temp->next){
                temp=temp->next;
                lenght++;
            }
            k=k%lenght;
            if(k==0){
                return head;
            }
            else{
                ListNode* curr=head;
                for(int i=0;i<lenght-k-1;i++){
                    curr=curr->next;

                }
                temp->next=head;
                head=curr->next;
                curr->next=NULL;
                return head;

            }
        }
    }
};