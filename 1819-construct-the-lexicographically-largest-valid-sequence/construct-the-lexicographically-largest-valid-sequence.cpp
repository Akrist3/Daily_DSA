class Solution {
public:
    vector<int> res;
    int N;
    vector<int> constructDistancedSequence(int n) {
        N = n;
        res = vector<int>(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        backtrack(0, used);
        return res;
    }

    bool backtrack(int idx, vector<bool>& used) {
        if (idx == res.size()) return true;
        if (res[idx] != 0) return backtrack(idx + 1, used);
        
        for (int num = N; num >= 1; --num) {
            if (used[num]) continue;
            if (num == 1) {
                res[idx] = 1;
                used[1] = true;
                if (backtrack(idx + 1, used)) return true;
                res[idx] = 0;
                used[1] = false;
            } else if (idx + num < res.size() && res[idx + num] == 0) {
                res[idx] = res[idx + num] = num;
                used[num] = true;
                if (backtrack(idx + 1, used)) return true;
                res[idx] = res[idx + num] = 0;
                used[num] = false;
            }
        }
        return false;
    }
};
