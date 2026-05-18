/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build(vector<int>& a,int l ,int r){
        if(l>r) return 0;
        int mid = (l+r)/2;
        TreeNode* root = new TreeNode(a[mid]);
        root->left = build(a,l,mid-1);
        root->right = build(a,mid+1,r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& a) {
        return build(a,0,a.size()-1); 
    }
};