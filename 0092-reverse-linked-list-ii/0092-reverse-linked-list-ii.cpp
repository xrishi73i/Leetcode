class Solution {
public:

    ListNode* reverseList(ListNode* head) {

        auto curr = head;
        ListNode* prev = NULL;

        while (curr != NULL) {

            auto next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }


    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // Nothing to reverse
        if (left == right)
            return head;

        ListNode* leftPrev = NULL;
        ListNode* lefti = NULL;
        ListNode* righti = NULL;
        ListNode* rightNext = NULL;

        auto curr = head;
        int idx = 1;

        // Find the 4 nodes
        while (curr != NULL) {

            if (idx == left - 1)
                leftPrev = curr;

            else if (idx == left)
                lefti = curr;

            else if (idx == right)
                righti = curr;

            else if (idx == right + 1)
                rightNext = curr;

            curr = curr->next;
            idx++;
        }

        // Cut the part to reverse
        righti->next = NULL;

        // Reverse lefti → righti
        reverseList(lefti);

        // Connect left part
        if (leftPrev != NULL)
            leftPrev->next = righti;
        else
            head = righti;

        // Connect right part
        lefti->next = rightNext;

        return head;
    }
};