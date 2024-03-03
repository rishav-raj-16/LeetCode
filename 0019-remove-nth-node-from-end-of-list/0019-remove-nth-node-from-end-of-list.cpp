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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int sz = 0;
        while(temp != NULL)
        {
            sz++;
            temp = temp->next;
        }

        if(sz==n)
        return head->next;

        int k = sz-n;
        ListNode* p = head;
        for(int i =1; i<k ; i++)
        {
            p=p->next;
        }
        p->next = p->next->next;
        return head;
    }
};









