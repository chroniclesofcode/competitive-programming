class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        using arr2 = array<int, 2>;
        vector<arr2> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {costs[i], capacity[i]};
        }
        sort(v.begin(), v.end());
        // have {costs, capacity} sorted
        int pmax = -1;
        int j = 0;
        int ans = 0;
        for (int i = n-1; i >= 0; i--) {
            if (v[i][0] >= budget) continue;
            while (j < n && v[j][0] + v[i][0] < budget) {
                if (pmax == -1 || v[j][1] > v[pmax][1]) {
                    pmax = j;
                }
                j++;
            }
            int curr = (pmax == -1) || (pmax == i) ? 0 : v[pmax][1];
            ans = max(ans, v[i][1] + curr);
        }
        return ans;
    }
};