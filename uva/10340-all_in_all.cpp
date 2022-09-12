#include <bits/stdc++.h>

using namespace std;

int main(void) {

    string s, t;
    int curr;
    while (cin >> s >> t) {
        curr = 0;
        for (char c : t) {
            if (s[curr] == c) {
                curr++;
            }
            if (curr == s.length()) {
                break;
            }
        }
        if (curr == s.length()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
}


