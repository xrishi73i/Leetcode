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
        ListNode* dummy = new ListNode(101);
        auto tail = dummy ;
        
        auto ptr1 = list1;
        auto ptr2= list2;

        while(ptr1 != NULL and ptr2!=NULL){
            if(ptr1->val < ptr2->val){
                tail->next = ptr1;
                tail = ptr1;
                ptr1 = ptr1->next;
            }else{
              tail->next = ptr2;
              tail = ptr2;
                ptr2 = ptr2->next;  
            }
        }
        if(ptr1 !=NULL){
            tail->next = ptr1;
        }
                if(ptr2 != NULL){
            tail->next = ptr2;
        }
        return dummy->next;
    }
    
};