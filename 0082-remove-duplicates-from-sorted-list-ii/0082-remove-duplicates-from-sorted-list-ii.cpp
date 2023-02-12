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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next == NULL)
        return head;
        
        ListNode * temp =new ListNode;
        ListNode * t =temp;
        t->next=head;
        while(head){
            if(head->next != NULL && head->val == head->next->val){
                while(head->next != NULL && head->val == head->next->val){
                    head=head->next;
                }
                head=head->next;
                t->next=head;
            }
            else{
                t=t->next;
                head=head->next;
            }
        }
        return temp->next;
    }
};