class Solution {
public:
    /*
    decreasing from the right, increasing but
    from the left, how long the sequence
    is. Then for every single element, we can
    just check i + k, i - k for each value in array
    by querying inc[i], dec[i] and the length
    */
    int inc[(int)1e5], dec[(int)1e5];
    vector<int> goodDaysToRobBank(vector<int>& s, int time) {
        int n = s.size();
        inc[0] = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] <= s[i-1]) {
                inc[i] = inc[i-1] + 1;
            } else {
                inc[i] = 1;
            }
        }
        dec[n-1] = 1;
        for (int i = n-2; i >= 0; i--) {
            if (s[i] <= s[i+1]) {
                dec[i] = dec[i+1] + 1;
            } else {
                dec[i] = 1;
            }
        }
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (inc[i] > time && dec[i] > time) {
                ret.push_back(i);
            }
        }
        /*
        cout << "inc: ";
        for (int i = 0; i < n; i++) {
            cout << inc[i] << ' ';
        }
        cout << "\ndec: ";
        for (int i = 0; i < n; i++) {
            cout << dec[i] << ' ';
        }
        cout << endl;
        */
        return ret;
    }
};
