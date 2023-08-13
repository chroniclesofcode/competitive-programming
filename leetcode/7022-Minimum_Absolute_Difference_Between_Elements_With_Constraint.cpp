class Solution {
public:
    /*
        Make a set, compare each element with element x ahead.
        lower bound the element x ahead, and keep the min dist.

        My original intuition was I had to somehow compare all
        the first i elements with the element i+x ahead, find
        the smallest dist. It wouldn't pass complexities so I
        had to somehow binary search. A set in the end was the
        solution using lower_bound
    */
    set<int> s;
    void debug() {
        for (auto it = s.begin(); it != s.end(); it++) {
            cout << *it << ' ';
        }
        cout << endl;
    }
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int ans = INT_MAX;
        
        for (int i = 0; i < nums.size() - x; i++) {
            int val = nums[i+x];
            s.insert(nums[i]);
            auto it = s.lower_bound(val);
            if (it != s.end()) {
                ans = min(ans, abs(val - *it));
            }
            if (it != s.begin() && s.size() > 0) {
                it--;
                ans = min(ans, abs(val - *it));
            }
            
        } 
        return ans;
    }
};
