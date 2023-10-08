class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& a, int k) {
        int n = a.size();
        #define pp pair<double, pair<int,int>>
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({(double)a[i]/a[n-1], {i, n-1}});
        }
        for (int i = 0; i < k-1; i++) {
            pp top = pq.top();
            pq.pop();
            int x1 = top.second.first;
            int x2 = top.second.second - 1;
            if (x1 < x2) {
                pq.push({(double)a[x1]/a[x2], {x1, x2}});
            }
        }
        pp top = pq.top();
        vector<int> ret = {a[top.second.first], a[top.second.second]};
        return ret;
    }
};
