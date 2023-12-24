class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1); hFences.push_back(m);
        vFences.push_back(1); vFences.push_back(n);
        unordered_map<long long, long long> hdiff;
        for (auto h1 : hFences) {
            for (auto h2 : hFences) {
                hdiff[abs(h1-h2)] = 1;
            }
        }
        long long ans = -1;
        for (auto v1 : vFences) {
            for (auto v2 : vFences) {
                long long va = abs((long long)v1 - v2);
                if (va == 0) continue;
                if (hdiff[va]) {
                    ans = max(va * va, ans);
                }
            }
        }
        return ans % ((int)1e9 + 7);
    }
};
