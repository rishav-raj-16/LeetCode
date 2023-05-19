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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextp ;
        while(curr){
            nextp = curr->next;
            curr ->next = prev;
            prev = curr;
            curr = nextp;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        temp = head;

        for(int i = 1; i < n/2; i++){
            temp = temp->next;
        }
        ListNode* mid = temp->next;
        temp->next = NULL;
        ListNode* rmid = reverse(mid);


        int ans = INT_MIN;
        while(rmid){
            ans = max(ans,head->val + rmid->val);
            head = head->next;
            rmid = rmid->next;
        }
        return ans; 
    }
};