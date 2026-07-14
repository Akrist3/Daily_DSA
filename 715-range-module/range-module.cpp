class RangeModule {
public:
    map<int, int> mp;

    RangeModule() {

    }

    void addRange(int left, int right) {
        auto it = mp.lower_bound(left);

        if (it != mp.begin()) {
            auto prev = it;
            --prev;
            if (prev->second >= left)
                it = prev;
        }

        while (it != mp.end() && it->first <= right) {
            left = min(left, it->first);
            right = max(right, it->second);
            it = mp.erase(it);
        }

        mp[left] = right;
    }

    bool queryRange(int left, int right) {
        auto it = mp.upper_bound(left);

        if (it == mp.begin())
            return false;

        --it;
        return it->second >= right;
    }

    void removeRange(int left, int right) {
        auto it = mp.lower_bound(left);

        if (it != mp.begin()) {
            auto prev = it;
            --prev;
            if (prev->second > left)
                it = prev;
        }

        vector<pair<int, int>> addBack;

        while (it != mp.end() && it->first < right) {
            if (it->first < left)
                addBack.push_back({it->first, left});

            if (it->second > right)
                addBack.push_back({right, it->second});

            it = mp.erase(it);
        }

        for (auto &p : addBack)
            mp[p.first] = p.second;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */