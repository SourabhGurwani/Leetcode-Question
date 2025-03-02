/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr){
            return nullptr;
        }
        
        ListNode* ptrA=headA;
        ListNode* ptrB=headB;
        while(ptrA!=nullptr){
            while(ptrB!=nullptr){
                if(ptrA!=ptrB){
                    ptrB=ptrB->next;
                }
                else{
                    return ptrB;
                }
            }
            ptrB=headB;
            ptrA=ptrA->next;
        }
        return nullptr;
//        while (ptrA != ptrB) {
//     if (ptrA == nullptr) {
//         ptrA = headB;  // If ptrA reaches the end, move it to the head of B
//     } else {
//         ptrA = ptrA->next;  // Otherwise, move to the next node
//     }

//     if (ptrB == nullptr) {
//         ptrB = headA;  // If ptrB reaches the end, move it to the head of A
//     } else {
//         ptrB = ptrB->next;  // Otherwise, move to the next node
//     }
// }
// return ptrA;
    }
};