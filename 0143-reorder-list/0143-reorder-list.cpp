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
   ListNode* getmiddle(ListNode* head){
        auto slow = head;
        auto fast = head->next; // will give the first middle  
        while(fast != NULL and fast->next != NULL){
            slow = slow->next ;
            fast = fast->next->next;
        }
        return slow;

    }
    ListNode* reverse(ListNode* head){
        auto curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;

    }
    void reorderList(ListNode* head) {
        auto mid = getmiddle(head);
        auto ptr = mid->next;
        mid->next = NULL;
        auto second = reverse(ptr);
        auto first = head;
        while(first!= NULL and second !=NULL){
         auto nextfirst = first->next;
         auto nextsecond = second->next;

         first->next = second;
         second->next = nextfirst;
         first = nextfirst;
        second = nextsecond;
        }
        
    
    }
};