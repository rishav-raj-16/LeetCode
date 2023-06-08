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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> vec(m, vector<int> (n, -1));
        
        int lc = 0, rc = n-1;
        int ur = 0, br = m-1;
        while(head){
            for(int i = lc; i <= rc && head; i++){
                vec[ur][i] = head->val;
                head = head->next;
            }
            ur++;
            for(int i = ur; i <= br && head; i++){
                vec[i][rc] = head->val;
                head = head->next;
            }
            rc--;
            for(int i = rc; i >= lc && head; i--){
                vec[br][i] = head->val;
                head = head->next;
            }
            br--;
            for(int i = br; i >= ur && head; i--){
                vec[i][lc] = head->val;
                head = head->next;
            }
            lc++;
        }
        return vec;
    }
};