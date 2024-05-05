class Solution {
public:
    vector<int> c;
    int cost1, cost2;
    long long solve(long long tot, int extra) {
        long long more = extra * c.size() + tot;
        int big = extra + c.back();
        long long c1only = (long long)more * cost1;
        long long exclude_big = more - big;
        long long c2 = 0;
        if (big > exclude_big) {
            c2 = (exclude_big)*cost2 + (big-exclude_big)*cost1;
        } else {
            c2 = (more/2)*cost2 + (more%2)*cost1;
        }
        return min(c1only, c2);
    }
    int minCostToEqualizeArray(vector<int>& nums, int _cost1, int _cost2) {
        cost1 = _cost1; cost2 = _cost2;
        int n = nums.size();
        int md = (int)1e9 + 7;
        int target = 0;
        long long ans = 0;
        long long sm = 0;
        for (int i = 0; i < n; i++) {
            target = max(target, nums[i]);
        }
        if (cost1 * 2 <= cost2) {
            for (int i = 0; i < n; i++) ans += (target - (long long)nums[i]) * cost1;
            return ans % md;
        }
        long long tot = 0;
        for (int i = 0; i < n; i++) {
            c.push_back(target-nums[i]);
            tot += target - nums[i];
        }
        sort(c.begin(), c.end());
        ans = LLONG_MAX;
        long long reach = target;
        for (int i = 0; i <= reach; i++) {
            ans = min(ans, solve(tot, i));
        }
        return ans % md;
    }
};
