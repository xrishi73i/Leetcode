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
    ListNode* deleteMiddle(ListNode* head) {
        auto slow = head;
        auto fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        auto p = head;
        if(head->next == NULL){
            return {};
        }
        while(p->next != slow){
            p = p->next;
        }
        auto temp = p;
        temp->next = slow->next;
        delete slow;
        return head;

    
    }
    
};