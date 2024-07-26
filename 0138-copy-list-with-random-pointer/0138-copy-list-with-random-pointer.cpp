/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> mp;
        Node* ans = new Node(0);
        Node* temp = ans;
        auto p = head;
        
        while(p) {
            Node* newNode = new Node(p->val);
            mp[p] = newNode;
            temp->next = newNode;
            temp = temp->next;
            p = p->next;
        }
        
        p = head;
        temp = ans->next;
        
        while(p) {
            if(p->random == NULL) {
                temp->random = NULL;
            }else {
                temp->random = mp[p->random];
            }
            p = p->next;
            temp = temp->next;
        }
        return ans->next;
    }
};