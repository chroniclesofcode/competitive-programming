class Solution {
public:
    static const int MX = (int)1e4 + 1;
    int left[MX][10][10];
    int right[MX][10][10];
    int countPalindromes(string s) {
      /*
        for each index i, how many times is it the center of a palindrome?
      */
      int n = s.size();
      unordered_map<int, int> m;
      for (int i = 0; i < n; i++) {
        int ch = s[i] - '0';
        for (int j = 0; j < 10; j++) {
          if (i > 0) {
            for (int k = 0; k < 10; k++) {
              left[i][j][k] += left[i-1][j][k];
            }
          }
          left[i][j][ch] += m[j];

        }
        m[ch]++;
      }
      m.clear();
      for (int i = n-1; i >= 0; i--) {
        int ch = s[i] - '0';
        for (int j = 0; j < 10; j++) {
          if (i < n-1) {
            for (int k = 0; k < 10; k++) {
              right[i][j][k] += right[i+1][j][k];
            }
          }
          right[i][j][ch] += m[j];
        }
        m[ch]++;
      }
      long long ans = 0;
      for (int i = 2; i < n - 2; i++) {
        for (int j = 0; j < 10; j++) {
          for (int k = 0; k < 10; k++) {
            int l = left[i-1][j][k];
            int r = right[i+1][j][k];
            ans += (long long)l * r;
            ans %= (int)1e9 + 7;
          }
        }
      }
      return ans;
    }
};
