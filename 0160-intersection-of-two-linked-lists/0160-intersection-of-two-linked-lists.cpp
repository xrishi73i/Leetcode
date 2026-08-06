class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        auto p1 = headA;
        auto p2 = headB;

        int count = 0;

        while (p1 != p2) {

            if (p1 == NULL) {
                p1 = headB;
                count++;
            } else {
                p1 = p1->next;
            }

            if (p2 == NULL) {
                p2 = headA;
                count++;
            } else {
                p2 = p2->next;
            }

            // Both pointers have switched once and
            // both became NULL again => no intersection.
            if (count == 4)
                return NULL;
        }

        return p1;
    }
};