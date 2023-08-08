class Solution {
public:
    /*
       This question is very easy (I did have some slight bugs with
       the 'dp' at the beginning.)

       So basically, you make a prefix array counting all occurences
       of each character. This should be a very obvious step since
       we are trying to find how many characters are between left
       and right in O(1). Then, simply just do the calculations - you
       the number of occurences of each letter by 2, since in a palindrome
       you can just align 2 chars together, add to your 'need' variable.
       Then, if the total sum is odd, your need can be subtracted one
       since one character can just be put in the middle. Now, we can
       divide our need by 2 since we only need half of them to become
       part of our palindrome, the other half can be replaced by
       the k factor. Now compare, and push your answer. :)
    */
    int dp[(int)1e5+1][26];
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> ans;
        for (int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';
            if (i > 0) {
                for (int j = 0; j < 26; j++) {
                    dp[i][j] = dp[i-1][j];
                }
            }
            dp[i][ch]++;
        }
        for (auto e : queries) {
            int left = e[0];
            int right = e[1];
            int k = e[2];

            int need = 0;
            for (int j = 0; j < 26; j++) {
                int reml = left > 0 ? dp[left-1][j] : 0;
                need += (dp[right][j] - reml) % 2;
            }
            if (left - right + 1 % 2 == 1) {
                need--;
            }
            if (need/2 > k) {
                ans.push_back(false);
            } else {
                ans.push_back(true);
            }
        }
        return ans;
    }
};
