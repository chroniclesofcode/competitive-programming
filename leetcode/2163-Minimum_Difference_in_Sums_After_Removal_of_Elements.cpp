class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        /*
            go through every element of nums, and partition at i.
            you have size l and size r. We have to find the l-n
            greatest elements on the left and remove them, and find the
            r-n lowest elements on the right and remove them. The running
            min of the difference is the answer. We can also do the
            calculations of the greatest/smallest while running, so it's
            O(nlogn).
        */
        #define LL long long
        priority_queue<int> l;
        priority_queue<int, vector<int>, greater<int>> r;
        int n = nums.size();
        vector<LL> left(n), right(n);
        LL ans = LLONG_MAX;
        LL lsum = 0, rsum = 0;
        int half = n / 3;
        for (int i = n-1; i >= 0; i--) {
            rsum += nums[i];
            r.push(nums[i]);
            if (r.size() > half) {
                rsum -= r.top();
                r.pop();
            }
            right[i] = rsum;
        }
        for (int i = 0; i < n; i++) {
            lsum += nums[i];
            l.push(nums[i]);
            if (l.size() > half) {
                lsum -= l.top();
                l.pop();
            }
            left[i] = lsum;
        }
        for (int i = half-1; i < n-half; i++) {
            ans = min(ans, left[i]-right[i+1]);
        }
        return ans;
    }
};
