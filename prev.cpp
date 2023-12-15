class Solution {
public:
    static constexpr int mx = (int)1e5 + 1;
    static constexpr int inf = (int)1e9 + 1;
    int minOperations(vector<int>& t, vector<int>& arr) {
        unordered_map<int, int> m;
        for (int i = 0; i < t.size(); i++) {
            m[t[i]] = i;
        }
        vector<int> arridx;
        for (int i = 0; i < arr.size(); i++) {
            if (m.count(arr[i])) arridx.push_back(m[arr[i]]);
        }
        vector<int> sz;
        for (int i = 0; i < arridx.size(); i++) {
            auto it = lower_bound(sz.begin(), sz.end(), arridx[i]);
            if (it == sz.end()) sz.push_back(arridx[i]);
            else *it = arridx[i];
        }
        return t.size() - sz.size();
    }
};
