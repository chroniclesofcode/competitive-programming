class Solution {
public:
    const static int MX = (int)1e5 + 1;
    vector<int> corr[MX];
    int vis[MX];
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> s;
        for (int i = n-1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] <= nums[i]) {
                s.pop();
            }
            if (!s.empty()) corr[s.top()].push_back(i);
            s.push(i);
        }
        deque<int> dq;
        for (int i = n-1; i >= 0; i--) {
            for (int u : corr[i]) {
                int v = nums[u];
                int lo = 0, hi = dq.size() - 1;
                auto it = upper_bound(dq.begin(), dq.end(), v);
                if (it != dq.end()) { 
                    res[u] = *it;
                }
            }
            while (!dq.empty() && dq.front() <= nums[i]) {
                dq.pop_front();
            }
            dq.push_front(nums[i]);
        }
        return res;
    }
};


