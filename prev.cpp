class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int n = order.size();
        int lo = 0, hi = n-1;
        vector<int> tmp;
        int ans = n;
        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            tmp.clear();
            string t = s;
            for (int i = 0; i <= mid; i++) {
                t[order[i]] = '*';
            }
            for (int i = 0; i < n; i++) {
                if (t[i] == '*') {
                    tmp.push_back(i);
                }class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int n = order.size();
        int lo = 0, hi = n-1;
        vector<int> tmp;
        int ans = n;
        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            tmp.clear();
            string t = s;
            for (int i = 0; i <= mid; i++) {
                t[order[i]] = '*';
            }
            for (int i = 0; i < n; i++) {
                if (t[i] == '*') {
                    tmp.push_back(i);
                }
            }
            long long ct = 0;
            for (int i = 0; i < tmp.size(); i++) {
                int left = tmp[i] - (i == 0 ? -1 : tmp[i-1]);
                int right = n - tmp[i];
                ct += (long long)(left) * right;
            }
            if (ct >= k) {
                hi = mid - 1;
                ans = min(ans, mid);
            } else {
                lo = mid + 1;
            }
        }
        return ans == n ? -1 : ans;
    }
};
            }
            long long ct = 0;
            for (int i = 0; i < tmp.size(); i++) {
                int left = tmp[i] - (i == 0 ? -1 : tmp[i-1]);
                int right = n - tmp[i];
                ct += (long long)(left) * right;
            }
            if (ct >= k) {
                hi = mid - 1;
                ans = min(ans, mid);
            } else {
                lo = mid + 1;
            }
        }
        return ans == n ? -1 : ans;
    }
};