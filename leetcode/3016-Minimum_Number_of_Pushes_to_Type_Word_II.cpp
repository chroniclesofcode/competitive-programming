class Solution {
public:
    int freq[26];
    int cost[26];
    int minimumPushes(string word) {
        for (auto c : word) {
            int ch = c - 'a';
            freq[ch]++;
        }
        vector<array<int,2>> arr;
        for (int i = 0; i < 26; i++) {
            arr.push_back({freq[i], i});
        }
        sort(arr.begin(), arr.end(), greater<array<int,2>>());
        int ct = 0;
        for (auto e : arr) {
            cost[e[1]] = ct/8 + 1;
            ct++;
        }
        int ans = 0;
        for (auto c : word) {
            int ch = c - 'a';
            ans += cost[ch];
        }
        return ans;
    }
};
