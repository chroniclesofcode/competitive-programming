class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> st;
        st.push(0);
        for (int i = 1; i < n; i++) {
            while (!st.empty() && nums[i] <= nums[st.top()]) {
                st.pop();
            }
            if (st.empty()) left[i] = 0;
            else left[i] = st.top()+1;
            st.push(i);
        }
        right[n-1] = n-1;
        st = stack<int>();
        st.push(n-1);
        for (int i = n-2; i >= 0; i--) {
            while (!st.empty() && nums[i] <= nums[st.top()]) {
                st.pop();
            }
            if (st.empty()) right[i] = n-1;
            else right[i] = st.top()-1;
            st.push(i);
        }
        
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] + 1;
            int target = threshold / len;
            if (target < nums[i]) {
                return len;
            }
        }
        
        return -1;
    }
};
/*
for each element, find out the next smaller element to the left, and
to the right. Then, calculate the threshold for it.
*/
