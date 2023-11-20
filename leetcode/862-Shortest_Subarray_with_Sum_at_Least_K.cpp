class Solution {
public:
    #define LL long long
    #define arr array<LL, 2>
    LL pref[(int)1e5+1];
    int shortestSubarray(vector<int>& nums, int k) {
        LL INF = INT_MAX;
        LL p = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            p += nums[i]; pref[i] = p;
        }
        deque<LL> dq;
        LL ans = INF;
        for (int i = 0; i < n; i++) {
            // Pop from front if >= k, because if i goes on, the
            // front will be never be shorter than current i.
            while (!dq.empty() && pref[i] - pref[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && pref[dq.back()] >= pref[i]) dq.pop_back();
            if (pref[i] >= k) ans = min(ans, (LL)i+1);
            dq.push_back(i);
        }
        return ans == INF ? -1 : ans;
    }
};

/*
// Alternate valid solution, but slow
// Monotonic deque, and lower_bound for the sol
int shortestSubarray(vector<int>& nums, int k) {
        LL INF = INT_MAX;
        LL p = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            p += nums[i]; pref[i] = p;
        }
        deque<arr> dq;
        dq.push_back({0, -1});
        LL ans = INF;
        for (int i = 0; i < n; i++) {
            while (!dq.empty() && dq.back()[0] > pref[i]) dq.pop_back();
            if (dq.empty() && pref[i] >= k) ans = min(ans, (LL)i+1);
            else {
                arr big = { pref[i]-k, INF };
                auto it = upper_bound(dq.begin(), dq.end(), big);
                if (it != dq.begin()) {
                    it--;
                    ans = min(ans, i - (*it)[1]);
                }
            }
            dq.push_back({pref[i], i});
        }
        return ans == INF ? -1 : ans;
    }
*/
