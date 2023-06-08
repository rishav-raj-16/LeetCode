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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* p = list1, *q = p;
        int x = 0, y = 0;
        
        while(p){
            if(x == a) break;
            q = p;
            p = p->next;
            x++, y++;
        }
        
        while(p){
            if(y == b) break;
            p = p->next;
            y++;
        }
        
        ListNode* r = list2;
        while(r->next != NULL){
            r = r->next;
        }
        // if(q == list1)
        //     list1 = list2;
        q->next = list2;
        r->next = p->next;
        
        return list1;
    }
};