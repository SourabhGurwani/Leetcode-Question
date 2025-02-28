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
    ListNode* sortList(ListNode* head) {
           if (!head) {
        return nullptr;
    }

    std::vector<int> values;
    ListNode* current = head;
    while (current) {
        values.push_back(current->val);
        current = current->next;
    }

    std::sort(values.begin(), values.end());

    current = head;
    int i = 0;
    while (current) {
        current->val = values[i++];
        current = current->next;
    }

    return head;
    }
};