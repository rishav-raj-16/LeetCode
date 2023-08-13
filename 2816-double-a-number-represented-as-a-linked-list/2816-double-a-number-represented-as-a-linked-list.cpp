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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr=head;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        int carry = 0;
        ListNode* ptr = head;
        while(ptr){
            int t = ptr->val*2;
            ptr->val = (t + carry)%10;
            carry = (t + carry)/10;
            if( !ptr->next && carry){
                ptr->next = new ListNode(carry); ptr = ptr->next; 
            }
            ptr = ptr->next;
        }
        return reverseList(head);
    }
};