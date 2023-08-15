class Solution {
public:
    /*
       Spent a LONG time on this question - very disappointed
       in myself since I saw 90% of the solution upon looking at
       the question. It's clear that you need a left and a right
       array to determine the range at which you calculate
       the subarrays -> left representing the leftmost element
       from the current element which is smaller than arr[i].

       The only problem was I was extremely stuck on how to 
       exclude duplicates. I tried thinking of other approaches
       such as subarrays, but to no avail. The duplicate counting
       was solved by restricting one side to LEQ and one to just LT.
       So basically, we allow the right side to go past the duplicate
       and count all the subarrays, but we only allow the left side
       to hit a duplicate and end right there.
    */
    int left[3*(int)1e4];
    int right[3*(int)1e4];
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        st = stack<int>();
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        const int MOD = 1e9 + 7;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += ((long long)(i - left[i]) * (right[i] - i) % MOD) * arr[i];
            ans %= MOD;
        }
        return ans;
    }
};
