class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Handle empty lists
        if (!list1) return list2;
        if (!list2) return list1;

        // Initialize the dummy node to simplify merging
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        // Merge the lists while both are non-empty
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // If one of the lists is not empty, append the remaining elements
        if (list1) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        // Return the merged list (skipping the dummy node)
        return dummy->next;
    }
};
