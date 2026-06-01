class TrieNode {
public:
    TrieNode* child[2];

    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

class Solution {
public:
    void insert(TrieNode* root, int num) {
        TrieNode* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!node->child[bit]) {
                node->child[bit] = new TrieNode();
            }

            node = node->child[bit];
        }
    }

    int findMax(TrieNode* root, int num) {
        TrieNode* node = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (node->child[1 - bit]) {
                ans |= (1 << i);
                node = node->child[1 - bit];
            } else {
                node = node->child[bit];
            }
        }

        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();

        for (int num : nums) {
            insert(root, num);
        }

        int maxi = 0;

        for (int num : nums) {
            maxi = max(maxi, findMax(root, num));
        }

        return maxi;
    }
};