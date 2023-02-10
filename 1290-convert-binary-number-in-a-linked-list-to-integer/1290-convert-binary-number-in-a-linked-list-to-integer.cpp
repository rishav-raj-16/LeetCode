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
    int getDecimalValue(ListNode* head) {
        if(head==0 && head->next == NULL)
        return 0;
        ListNode *p=head;
        vector<int> temp;
        while(head)
        {
            temp.push_back(head->val);
            head=head->next;
        }
        reverse(temp.begin(),temp.end());

        int res=0, q=0;
        for(int i =0 ; i<temp.size() ; i++)
        {
            res +=(pow(2,q)*temp[i]);
            q++;
        }
        return res;
    }
};