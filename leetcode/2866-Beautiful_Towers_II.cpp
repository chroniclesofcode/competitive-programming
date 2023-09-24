class Solution {
public:
    long long maximumSumOfHeights(vector<int>& h) {
        #define LL long long
        LL n = h.size();
        vector<LL> left(n+1, 0), right(n+1, 0);
        stack<LL> s1, s2;
        LL ans = 0;
        for (LL i = 0; i < n; i++) {
            while (!s1.empty() && h[s1.top()] >= h[i]) {
                s1.pop();
            }
            if (s1.empty()) {
                left[i] = (i+1) * h[i];
            } else {
                left[i] = (i - s1.top()) * h[i] + left[s1.top()];
            }
            s1.push(i);
        }
        for (LL i = n-1; i >= 0; i--) {
            while (!s2.empty() && h[s2.top()] >= h[i]) {
                s2.pop();
            }
            if (s2.empty()) {
                right[i] = (n-i) * h[i];
            } else {
                right[i] = (s2.top() - i) * h[i] + right[s2.top()];
            }
            s2.push(i);
        }
        for (LL i = 0; i < n; i++) {
            ans = max(ans, left[i] + right[i] - h[i]);
        }
        
        return ans;
    }
};


