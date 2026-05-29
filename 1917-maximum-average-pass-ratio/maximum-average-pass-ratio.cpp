class Solution {
public:
    double gain(int p, int t) {
        return (double)(p + 1) / (t + 1) - (double)p / t;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        priority_queue<
            tuple<double, int, int>
        > pq;

        for (auto &c : classes) {
            pq.push({gain(c[0], c[1]), c[0], c[1]});
        }

        while (extraStudents--) {
            auto [g, p, t] = pq.top();
            pq.pop();

            p++;
            t++;

            pq.push({gain(p, t), p, t});
        }

        double sum = 0;

        while (!pq.empty()) {
            auto [g, p, t] = pq.top();
            pq.pop();

            sum += (double)p / t;
        }

        return sum / classes.size();
    }
};