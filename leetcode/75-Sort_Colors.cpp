class Solution {
public:
    int partition(vector<int> &nums, int l, int r) {
        int piv = nums[r];
        int j = l-1;
        for (int i = l; i < r; i++) {
            if (nums[i] < piv) {
                j++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[j+1], nums[r]);
        return j+1;
    }

    void qs(vector<int> &nums, int l, int r) {
        if (l >= r) return;
        int p = partition(nums, l, r);
        qs(nums, l, p-1);
        qs(nums, p+1, r);
    }

    void sortColors(vector<int>& nums) {
        qs(nums, 0, nums.size() - 1);
    }
};
