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
    unordered_map<int, int> freq; // To store frequency of each subtree sum
    int maxFreq = 0;

    // Function to calculate subtree sums recursively
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);
        int sum = leftSum + rightSum + root->val;

        freq[sum]++;
        maxFreq = max(maxFreq, freq[sum]);

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (!root) return {};
        dfs(root);

        vector<int> result;
        for (auto &p : freq) {
            if (p.second == maxFreq)
                result.push_back(p.first);
        }
        return result;
    }
};