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
    ListNode* swapNodes(ListNode* head, int k) {
        int sz = 0;
        ListNode* temp = head;
        while(temp != NULL){
            sz++;
            temp = temp->next;
        }
        int n = sz-k;
        ListNode* p = head;
        ListNode* q = head;
        for(int i = 1; i <= n; i++){
            p = p->next;
        }
        for(int i = 1; i < k; i++){
            q = q->next;
        }
        swap(p->val, q->val);
        return head;
    }
};