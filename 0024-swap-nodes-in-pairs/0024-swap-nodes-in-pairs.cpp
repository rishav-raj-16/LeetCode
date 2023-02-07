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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
        return head;
        
        if(head->next == NULL)
        return head;
        
        ListNode *p=head; 
        ListNode *q=p->next;
        while(p!=NULL && q!=NULL)
        {
            swap(p->val,q->val);
            if(p->next->next == NULL || q->next->next == NULL) 
            break;
            else
            {
                p=p->next->next;
                q=q->next->next;
            }
        }
        return head;
    }
};