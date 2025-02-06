// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//          if (!head || !head->next) {
//             return nullptr; // No cycle if the list is empty or has only one node
//         }
//         ListNode* slow=head;
//         ListNode* fast=head;
//         ListNode* temp=head;
//         // int i=-1;
//         while(fast!=nullptr && fast->next!=nullptr){
//             slow=slow->next;
//             fast=fast->next->next;
//             if(slow==fast){
//                 while(slow!=nullptr && slow->next!=nullptr){
                    
//                     // i++;
//                     if(temp==slow){
//                         return slow;
//                     }
//                     temp=temp->next;
//                 }
                
//                 // return true;
//             }
//         }
//         // return false;
//         return NULL;
        
//     }
// };
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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return nullptr; // No cycle if the list is empty or has only one node
        }

        ListNode *slow = head;
        ListNode *fast = head;

        // Phase 1: Detect the cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break; // Cycle detected!
            }
        }

        if (!fast || !fast->next) { // No cycle found
            return nullptr;
        }

        // Phase 2: Find the start of the cycle (Corrected Logic)
        slow = head; // Reset slow to the head
        while (slow != fast) {
            slow = slow->next; // Move slow one step
            fast = fast->next; // Move fast one step
        }

        return slow; // slow (or fast) now points to the start of the cycle
    }
};