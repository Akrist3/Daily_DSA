/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* newnode = node->next;
        node-> val = newnode-> val ;
        node->next = newnode->next;
        delete newnode;
        
    }
        
};