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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        ListNode* p = head, *q = head->next, *s = q;
        while(p->next && q->next){
            p->next = q->next;
            q->next = p->next->next;
            p = p->next;
            q = q->next;
        }
        p->next = s;
        return head;
    }
};