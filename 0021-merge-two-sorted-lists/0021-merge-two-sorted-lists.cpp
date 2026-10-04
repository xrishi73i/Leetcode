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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        auto tail = dummy;
        auto a = list1;
        auto b = list2 ;
        while(a!=NULL and b!= NULL){
            if(a->val <= b->val){
                tail->next = a;
                a = a->next;
            }else{
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        //remaining parts 
        if(a!= NULL){
            tail->next = a;
            a = a->next;
        }if(b != NULL){
            tail->next = b;
            b = b->next;
        }
        return dummy->next;
    }
};