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
        ListNode* find_mid(ListNode*x){   //function to find mid of the LL...
            ListNode *slow=x;
            ListNode *fast =x->next;

            while(fast && fast->next!=NULL)
            {
                slow=slow->next;
                fast=fast->next->next;
            }
            return slow;
        }

        ListNode* merge(ListNode* l,ListNode* r){

            if(l==NULL)
                return r;
            if(r==NULL)
                return l;

            ListNode* store = new ListNode;
            ListNode* temp =store;
            while(l&&r)
            {
                if(l->val<r->val){
                    temp->next=l;
                    l=l->next;
                }
                else{
                    temp->next=r;
                    r=r->next;
                }
                temp=temp->next;
            }
            while(l){
                temp->next=l;
                l=l->next;
                temp=temp->next;
            }
            while(r){
                temp->next=r;
                r=r->next;
                temp=temp->next;
            }
            return store->next;
        }

        ListNode* sortList(ListNode* head) {
            if(head == NULL || head->next == NULL)
            return head;
            ListNode *mid= find_mid(head);
            ListNode *left=head;              //Making 2 deferent LL.. 
            ListNode *right=mid->next;
            mid->next=NULL;                   //Breaking the LL...

            left=sortList(left);
            right=sortList(right);

            ListNode* ans=merge(left,right);

            return ans;
        }
    };