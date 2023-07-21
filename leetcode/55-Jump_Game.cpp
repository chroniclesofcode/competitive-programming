class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxreachable = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxreachable) {
                return false;
            }
            maxreachable = max(maxreachable, i+nums[i]);
        }
        return true;
    }
}
