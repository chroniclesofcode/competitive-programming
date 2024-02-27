class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& c) {
        int lo = 0, hi = c.size()-1;
        int ans = c.size();
        int n = nums.size();
        for (auto& e : c) e--;

        auto possible = [&](int mid) {
            if (mid == 0) return nums.size() == 1 && nums[0] == 0;
            vector<int> marked(n);
            vector<int> first(n, -1);
            int free = 0;
            for (int i = 0; i <= mid; i++) {
                if (first[c[i]] == -1 && nums[c[i]] > 0) {
                    first[c[i]] = i;
                    marked[c[i]] = 1;
                } else {
                    free++;
                }
            }
            if (free < n) return false;
            free -= n;
            using arr2 = array<int,2>;
            priority_queue<arr2, vector<arr2>, greater<arr2>> pq;
            int cap = 0;
            for (int i = mid; i >= 0; i--) {
                if (first[c[i]] == i) {
                    pq.push({ nums[c[i]], c[i] });
                    if (cap == 0) {
                        auto tp = pq.top();
                        pq.pop();
                        marked[tp[1]] = 0;
                        cap++; // can use it
                        free++;
                    } else {
                        cap--;
                    }
                } else {
                    cap++;
                }
            }
            for (int i = 0; i < n; i++) {
                if (!marked[i]) free -= nums[i];
                if (free < 0) return false;
            }
            return true;
        };
        
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if (possible(mid)) {
                hi = mid-1;
                ans = min(ans, mid);
            } else {
                lo = mid+1;
            }
        }
        return (ans == c.size() ? -1 : ans+1);
    }
};

/*
binary search
it's always optimal to change a number to 0 at
the first occurrence to allow everything more
room. 
we want to iterate backwards, when we hit a 
first occurrence, we want to match it to an empty
slot. If we run out of empty slots but need to
set an occurrence to 0, kick out the lowest 
number we have travelled on. 
*/
