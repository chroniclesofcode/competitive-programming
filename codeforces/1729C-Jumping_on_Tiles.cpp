#include <bits/stdc++.h>
//#include <iostream>
using namespace std;

void solve();

int main(void) {
    int t;
    cin >> t;

    while (t--) solve();

}

// Simple implementation problem
// Main takeaway is shortest path is always directly
// from first letter to the end letter, but your
// max paths comes from jumping on each letter in between
// the two: this doesn't affect the min distance, but does
// impact the max jumps. 

void solve() {
    string s;
    cin >> s;
    int beg = s[0];
    int end = s[s.length()-1];
    unordered_map<int, deque<int>> m;
    for (int i = 0; i < s.length(); i++) m[s[i]].push_back(i);
    sort(s.begin(), s.end());

    vector<int> res;
    bool begun = false;
    int jumps = 0;
    if (end - beg >= 0) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == beg) {
                begun = true;
            }
            if (begun) {
                deque<int>& val = m[s[i]];
                //cout << val.front()+1 << " ";
                res.push_back(val.front()+1);
                val.pop_front();
                jumps++;
            }
            if (s[i] == end && m[s[i]].size() == 0) {
                break;
            }
        }
    } else {
        for (int i = s.length()-1; i >= 0; i--) {
            if (s[i] == beg) {
                begun = true;
            }
            if (begun) {
                deque<int>& val = m[s[i]];
                //cout << val.front()+1 << " ";
                res.push_back(val.front()+1);
                val.pop_front();
                jumps++;
            }
            if (s[i] == end && m[s[i]].size() == 0) {
                break;
            }
        }
    }
    cout << abs(end - beg) << " " << jumps << endl;
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
    cout << endl;
}


