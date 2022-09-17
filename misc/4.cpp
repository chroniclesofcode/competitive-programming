#include <bits/stdc++.h>

using namespace std;

#define LL long long

void solve();

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    solve();
}

void solve() {
    // hands sorted by number
    // hands sorted by suit
    vector<pair<int, char>> num(7);
    vector<pair<char, int>> suit(7);
    unordered_map<int, int> kind;

    for (int i = 0; i < 7; i++) {
        string s;
        cin >> s;
        char first = s[0];
        char second = s[1];
        int fnum = -1;
        if (first == 'A') {
            fnum = 14;
        } else if (isdigit(first)) {
            fnum = first - '0';
        } else if (first == 'T') {
            fnum = 10;
        } else if (first == 'J') {
            fnum = 11;
        } else if (first == 'Q') {
            fnum = 12;
        } else if (first == 'K') {
            fnum = 13;
        }

        num[i] = make_pair(fnum, second);
        suit[i] = make_pair(second, fnum);
        kind[fnum]++;
    }
    sort(num.begin(), num.end());
    sort(suit.begin(), suit.end());
    /*
    for (int i = 0; i < 7; i++) {
        cout << num[i].first << " of " << num[i].second << endl;
    }
    cout << "\n BREAK \n";
    for (int i = 0; i < 7; i++) {
        cout << suit[i].first << " of " << suit[i].second << endl;
    }
    */

    // Calculations... skull emoji
    
    // Straight flush

    bool straight_flush = false;
    bool four = false;
    //bool full_house = false;
    bool flush = false;
    bool straight = false;
    //bool three = false;
    bool twopair = false;
    //bool onepair = false;

    int straight_ct = 1;
    int sflush_ct = 1;
    int flush_ct = 1;
    int twopair_ct = -1;
    
    bool fh_three = false;
    bool fh_two = false;


    if (num[6].first == 14 && num[0].first == 2) {
        straight_ct++;
        if (num[6].second == num[0].second) {
            sflush_ct++;
        }
    }
    for (int i = 1; i < 7; i++) {
        // Counts straight, straight flush
        if (num[i].first == num[i-1].first + 1) {
            straight_ct++;
            if (num[i].second == num[i-1].second) {
                sflush_ct++;
                if (sflush_ct == 5) {
                    straight_flush = true;
                }
            } else {
                sflush_ct = 1;
            }
            if (straight_ct == 5) {
                straight = true;
            }
        } else {
            straight_ct = 1;
        }
        // Counts flush
        if (suit[i].first == suit[i-1].first) {
            flush_ct++;
            if (flush_ct == 5) {
                flush = true;
            }
        } else {
            flush_ct = 1;
        }
        // Checks for four of a kind
        // Checks for three of a kind
        // Checks for pair
        int tmp = kind[num[i].first];
        if (tmp == 4) {
            four = true;
        } else if (tmp == 3) {
            fh_three = true;
        } else if (tmp == 2) {
            // Counts two pair
            if (fh_two && twopair_ct != num[i].first) {
                twopair = true;
            }
            fh_two = true;
            twopair_ct = num[i].first;
        }
    }

    if (straight_flush) {
        cout << "straight flush";
    } else if (four) {
        cout << "four of a kind";
    } else if (fh_three && fh_two) {
        cout << "full house";
    } else if (flush) {
        cout << "flush";
    } else if (straight) {
        cout << "straight";
    } else if (fh_three) {
        cout << "three of a kind";
    } else if (twopair) {
        cout << "two pair";
    } else if (fh_two) {
        cout << "one pair";
    } else {
        cout << "high card";
    }

    cout << '\n';

}
   
