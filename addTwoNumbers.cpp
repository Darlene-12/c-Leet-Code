class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(); // Dummy node for building the result
        ListNode* current = dummy;       // Pointer to the current node
        int carry = 0;                   // Carry initialized to 0

        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            // Get values from l1 and l2 or 0 if they are null
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Calculate sum and carry
            int sum = val1 + val2 + carry;
            carry = sum / 10; // Carry is the tens digit
            int value = sum % 10; // Value is the ones digit

            // Create a new node with the value and attach to the result list
            current->next = new ListNode(value);
            current = current->next; // Move to the next node

            // Advance l1 and l2 if they are not null
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return dummy->next; // Return the next of dummy (actual result head)
    }
};
