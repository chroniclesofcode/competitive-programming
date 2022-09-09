#include <bits/stdc++.h>

using namespace std;

int keydiff(int a, int b) {
    int big = max(a, b);
    int small = min(a, b);
    return min(big-small, 'z'-big+small-'a'+1);
}

// Basically brute force, we go through each character
// then find the differences, then note that our cursor
// has to go to the 'edges' of our range and do the
// appropriate calcs.

int main(void) {
    int n, p;
    cin >> n >> p;
    p--;
    string s;
    cin >> s;
    int len = s.length() % 2 == 0 ? s.length() : s.length() - 1;
    len /= 2;

    int count = 0;
    int beg = p >= len ? len : 0;
    int end = p >= len ? n : len;

    if ((s.length() % 2) == 1 && beg == len) {
        beg++;
    }
    int left = -1;
    int right = beg;

    for (int i = beg; i < end; i++) {
        int d = keydiff(s[i], s[s.length() - 1 - i]);
        //cout << "d: " << d << " for " << s[i] << endl;
        count += d;
        if (d != 0) {
            if (left == -1) left = i;
            right = i;
        }
    }
    if (left == -1) {
        cout << 0 << endl;
        return 0;
    }

    count += right - left + min(abs(p-left), abs(p-right));
    /*cout << "len: "<< len << ", " << left << " " << right << " " << endl;
    cout << beg << " " << end << endl;*/

    cout << count << endl;
}

