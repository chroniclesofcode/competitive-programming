class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        int n = h.size();
        int lo = 0;
        int hi = n-1;
        int ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            int b = bricks;
            int l = ladders;
            set<array<int,2>> s;
            for (int i = 1; i <= mid; i++) {
                if (h[i] > h[i-1]) {
                    int sz = s.size();
                    if (sz < ladders) {
                        s.insert({h[i]-h[i-1], i});
                    } else if (sz && (*s.begin())[0] < h[i] - h[i-1]) {
                        s.erase(s.begin());
                        s.insert({h[i]-h[i-1], i});
                    }
                }
            }
            bool flag = true;
            for (int i = 1; i <= mid; i++) {
                if (h[i] > h[i-1]) {
                    if (s.count({h[i]-h[i-1],i}) && l > 0) {
                        l--;
                    } else if (b >= h[i] - h[i-1]) {
                        b -= h[i] - h[i-1];
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                ans = max(ans, mid);
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        return ans;
    }
};
