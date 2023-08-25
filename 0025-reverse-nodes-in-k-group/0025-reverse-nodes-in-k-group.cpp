class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;

        // Count the number of nodes in the linked list
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }

        // If there are at least k nodes, reverse them
        if (count == k) {
            curr = reverseKGroup(curr, k); // Recurse for the next group
            while (count > 0) {
                ListNode* temp = head->next;
                head->next = curr;
                curr = head;
                head = temp;
                count--;
            }
            head = curr; // Update head to the new start of the reversed group
        }
        return head;
    }
};
