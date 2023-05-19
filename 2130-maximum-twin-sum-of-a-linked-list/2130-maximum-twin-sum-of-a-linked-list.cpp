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
//     Function to reverse the string...
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
        ListNode* fast = head, *slow = head;
        
//         Using fast/slow method to find mid of the L.List...
        
        while(fast){
            fast = fast->next->next;
            slow = slow->next;
        }
//         Calling reverse function 
        ListNode* mid = reverse(slow);
        
        int ans = INT_MIN;
        while(mid){
            ans = max(ans,head->val + mid->val);
            head = head->next;
            mid = mid->next;
        }
        return ans; 
    }
};