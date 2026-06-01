class TrieNode {
public:
    TrieNode* child[2];
    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit])
                node->child[bit] = new TrieNode();
            node = node->child[bit];
        }
    }

    int getMaxXor(int num) {
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
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> q;
        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(q.begin(), q.end());

        Trie trie;
        vector<int> ans(queries.size());
        int idx = 0;
        int n = nums.size();
        for (auto &it : q) {
            int mi = it.first;
            int xi = it.second.first;
            int queryIdx = it.second.second;
            while (idx < n && nums[idx] <= mi) {
                trie.insert(nums[idx]);
                idx++;
            }
            if (idx == 0) {
                ans[queryIdx] = -1;
            } else {
                ans[queryIdx] = trie.getMaxXor(xi);
            }
        }
        return ans;
    }
};