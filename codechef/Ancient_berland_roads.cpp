#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    solve();
}

const LL MAXSZ = 1e5 * 6 + 20;
list<LL> pop[MAXSZ]; // people in each city
multiset<LL> adj[MAXSZ];
LL city[MAXSZ]; // dsu
LL nodes[MAXSZ]; // Size of nodes for dsu
LL total[MAXSZ]; // stores population for dsu
multiset<LL, greater<LL>> track;
vector<vector<LL>> paths; // stores population for dsu
vector<LL> ret;

void Debug(LL n) {
    cout << "populations ";
    for (LL i = 0; i < n; i++) {
        cout << *pop[i].begin() << " ";
    }
    cout << endl;
    cout << "dsu ";
    for (LL i = 0; i < n; i++) {
        cout << city[i] << " ";
    }
    cout << endl;
    cout << "total ";
    for (LL i = 0; i < n; i++) {
        cout << total[i] << " ";
    }
    cout << endl;
}

LL Find(LL a) {
    if (a == city[a]) {
        return a;
    }
    return city[a] = Find(city[a]);
}

void Union(LL a, LL b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        // a must be bigger
        if (nodes[a] < nodes[b]) {
            swap(a, b);
        }
        track.erase(track.find(total[b]));
        track.erase(track.find(total[a]));
        total[a] += total[b];
        track.insert(total[a]);
        city[b] = a;
        nodes[a] += nodes[b];
    }
}


// We remove all the roads first, then we reverse the
// array and actually ADD roads to it.
// We keep track of the connected components via union-find data
// structure. It will also store the amount of population within
// as well. Every time we union, the population will get incremented
// At the very end, we will do a O(n) loop and determine the max :D
void solve() {
    LL n, m, q;
    cin >> n >> m >> q;
    LL ppl;
    for (LL i = 0; i < n; i++) {
        cin >> ppl;
        pop[i].push_front(ppl);
        // dsu init
        total[i] = ppl;
        track.insert(ppl);
        nodes[i] = 1;
        city[i] = i;
    }
    paths.reserve(m + 20);
    LL x, y;
    // sets our map of indices
    for (LL i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        paths[i] = { x, y };
        adj[x].insert(y);
        adj[y].insert(x);
    }

    vector<vector<LL>> queries;
    ret.reserve(q);
    char c;
    LL a, b;
    for (LL i = 0; i < q; i++) {
        cin >> c;
        if (c == 'P') {
            cin >> a >> b;
            a--;
            queries.push_back({ (LL)c, a, b });
            pop[a].push_front(b);
            track.erase(track.find(total[a]));
            total[a] = b;
            track.insert(total[a]);
        } else if (c == 'D') {
            cin >> a;
            a--;
            queries.push_back({ (LL)c, a });
            adj[paths[a][0]].erase(adj[paths[a][0]].find(paths[a][1]));
            adj[paths[a][1]].erase(adj[paths[a][1]].find(paths[a][0]));
        }
    }

    for (LL i = 0; i < n; i++) {
        for (auto it = adj[i].begin(); it != adj[i].end(); it++) {
            Union(i, *it);
        }
    }

    // backwards traverse over queries...
    for (auto it = queries.rbegin(); it != queries.rend(); it++) {
        // 0 is P or D, 1 or 2 are values
        //Debug(n);
        //ret.push_back(*max_element(total, total+n));
        ret.push_back(*track.begin());

        vector<LL> val = *it;
        if (val[0] == 'P') {
            a = val[1];
            ppl = val[2];
            // Old town value
            LL tmp = ppl;
            pop[a].pop_front();
            // if tmp > 0, we lost population
            tmp -= *(pop[a].begin());
            LL found = Find(a);
            track.erase(track.find(total[found]));
            total[found] -= tmp;
            track.insert(total[found]);
        } else if (val[0] == 'D') {
            a = val[1];
            Union(paths[a][0], paths[a][1]);
        }
    }

    for (auto it = ret.rbegin(); it != ret.rend(); it++) {
        cout << *it << "\n";
    }
    
   
}




