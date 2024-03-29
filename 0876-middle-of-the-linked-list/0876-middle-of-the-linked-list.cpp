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
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while(temp){
            temp=temp->next;
            count++;
        }
        
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast !=NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(count%2==0)
            return slow->next;
        return slow;
    }
};