class Fenwick {
public:
    int n;
    vector<int> BIT;

    Fenwick() {}
    Fenwick(int sz) : n{sz}, BIT(sz+1, 0) {}

    void add(int x, int add) {
        x++;
        for (; x <= n; x += x&-x) {
            BIT[x] += add;
        }
    }

    int query(int x) {
        x++;
        int sum = 0;
        for (; x > 0; x -= x&-x) {
            sum += BIT[x];
        }
        return sum;
    }

    int pref(int st, int end) {
        if (st > end) return 0;
        return st <= 0 ? query(end) : query(end) - query(st-1);
    }
};
class Solution {
public:
    long long minInversionCount(vector<int>& nums, int k) {
        size_t n = nums.size();
        Fenwick ft(n + 1);
        map<int, int> m;
        for (auto num : nums) m[num] = 1;
        long long ct = 0;
        for (auto& [key, val] : m) {
            val = ct++;
        }
        for (int i = 0; i < n; i++) {
            nums[i] = m[nums[i]];
        }
        ct = 0;
        for (int i = 0; i < k; i++) {
            ct += ft.pref(nums[i]+1, n);
            ft.add(nums[i], 1);
        }
        long long ans = ct;
        int j = 0;
        for (int i = k; i < n; i++) {
            ct -= ft.pref(0, nums[j]-1);
            ft.add(nums[j], -1);
            j++;
            ct += ft.pref(nums[i]+1, n);
            ft.add(nums[i], 1);

            ans = min(ans, (long long)ct);
        }

        return ans;
    }
};