class Solution {
public:
    unordered_map<long long, bool> memo;
    unordered_map<int, int> pos;

    bool dfs(vector<int>& stones, int index, int jump) {
        if (index == stones.size() - 1)
            return true;

        long long key = ((long long)index << 32) | jump;

        if (memo.count(key))
            return memo[key];

        for (int nextJump = jump - 1; nextJump <= jump + 1; nextJump++) {
            if (nextJump <= 0)
                continue;

            int nextPosition = stones[index] + nextJump;

            if (pos.count(nextPosition)) {
                if (dfs(stones, pos[nextPosition], nextJump))
                    return memo[key] = true;
            }
        }

        return memo[key] = false;
    }

    bool canCross(vector<int>& stones) {
        if (stones[1] != 1)
            return false;

        for (int i = 0; i < stones.size(); i++)
            pos[stones[i]] = i;

        return dfs(stones, 0, 0);
    }
};