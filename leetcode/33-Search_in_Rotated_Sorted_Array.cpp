class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        int piv = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if (mid > 0 && nums[mid-1] > nums[mid]) {
                piv = mid;
                break;
            }
            if (nums[lo] < nums[hi]) {
                piv = lo;
                break;
            }
            if (nums[lo] > nums[mid]) {
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        // Should have found pivot by now, binary search the numbers using modulo.
        int rl = 0;
        int rr = nums.size() - 1;
        while (rl <= rr) {
            int mid = rl + (rr - rl)/2;
            int idx = (mid + piv) % nums.size();
            if (nums[idx] == target) {
                return idx;
            } else if (nums[idx] > target) {
                rr = mid-1;
            } else {
                rl = mid+1;
            }
        }
        return -1;
    }
};
