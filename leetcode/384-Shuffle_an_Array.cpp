class Solution {
public:
    vector<int> orig;
    Solution(vector<int>& nums) {
        orig = std::move(nums);
        srand(time(NULL));
    }
    
    vector<int> reset() {
        return orig;
    }
    
    vector<int> shuffle() {
        vector<int> res = orig;
        int n = res.size();
        for (int i = n-1; i > 0; i--) {
            int idx = rand() % (i+1);
            swap(res[i], res[idx]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
