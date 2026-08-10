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
        auto curr = head ;
        ListNode* prev = NULL;
        while(curr !=NULL){
            auto next = curr->next;
            curr->next = prev;
            prev =curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(-1);
        auto tail = dummy;
        auto ptr = head;
        while(ptr!=NULL){
            auto end = ptr;
            for(int i=1;i<k;i++){
                end = end->next;
                if(end ==NULL){
                    tail->next = ptr;
                    return dummy->next;
                }
            }
            
            auto nextstart = end->next;
            end->next = NULL;
            
            reverseList(ptr);
            tail->next = end;
            tail =ptr;
            ptr = nextstart;
        }
        return dummy->next;
    }
};