class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        using pp = pair<int,int>;
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({ nums[i], i+1 });
        }
        long long ans = 0;
        for (int i = 1; i <= right; i++) {
            pp p = pq.top();
            pq.pop();
            if (i >= left) {
                ans += p.first;
                ans %= (int)1e9 + 7;
            }
            if (p.second < n) {
                p.first += nums[p.second];
                p.second++;
                pq.push(p);
            }
        }
        return ans;
    }
};

