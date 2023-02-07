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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return head;
        
        while(head->val == val)
        {
            head=head->next;
            if(head == NULL) return NULL;
        }
       
        ListNode *p=head;
        
        while(p->next != NULL)
        {
            ListNode *q=p;
            p=p->next;
            if(p->val == val)
            {
                q->next=p->next;
                p=q;
            }
        }
        return head;
            
    }
};