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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* p = head;
        vector<int> res;
        int a;
        while(p)
        {
            ListNode*q=p;
            a=0;
            while(q)
            {
                if(q->val>p->val)
                {
                    res.push_back(q->val);
                    a++;
                    break;
                }
                else
                    q=q->next;
            }
            if(a==0)
                res.push_back(0);
            p=p->next;
        }
        
        return res;
    }
};