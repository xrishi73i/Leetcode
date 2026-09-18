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
    ListNode* reverseList(ListNode* head) {
        auto curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            auto nxt = curr->next;
          // move the arrow opposite site .
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head = prev;
        return head;
    }
    
};