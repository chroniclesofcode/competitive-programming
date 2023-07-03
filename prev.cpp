#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

#define INF numeric_limits<LL>::max() / 2
#define NINF -INF

const LL MX = 5 * 1e6;
//const LL MOD = 1e7;

#define arr array<int,4>
int n, nums[MX];
vector<arr> room;
set<array<int,2>> s;
/*
*/

void solve() {
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        room.push_back({x,0,i,y});
        room.push_back({y,1,i,x});
    }
    sort(room.begin(), room.end());
    int curr = 0;
    int ans = 0;
    for (int i = 0; i < room.size(); i++) {
        auto v = room[i];
        if (v[1]) {
            // Room ends
            curr--;
        } else {
            // New room
            curr++;
            int roomno = curr;
            if (s.size()) {
                auto minend = s.begin();
                if ((*minend)[0] < v[0]) {
                    roomno = (*minend)[1];
                    s.erase(minend);
                }
            }
            s.insert({v[3],roomno});
            nums[v[2]] = roomno;
        }
        ans = max(ans, curr);
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << nums[i] << ' ';
    }
    cout << endl;
}





