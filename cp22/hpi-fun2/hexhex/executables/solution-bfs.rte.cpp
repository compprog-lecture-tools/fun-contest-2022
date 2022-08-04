// h.cpp -> h.exe

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ll long long

using namespace std;

// clang-format off
int primes[] = {
    2, 3, 5, 7,
    11, 13, 17, 19,
    23, 29, 31, 37,
    41, 43, 47, 53,
};
// clang-format on

const ll left_bound = 0;
const ll right_bound = 2e9;

const int MAX_LEVEL = 12;
int bfs(int h, int w) {
    int level = 0;
    int level_size = 1;
    int next_level_size = 0;

    queue<ll> q;
    q.push(h);

    while (!q.empty() && level <= MAX_LEVEL) {
        if (level_size == 0) {
            level++;
            level_size = next_level_size;
            next_level_size = 0;
        }
        ll v = q.front();
        q.pop();
        level_size--;
        if (!(left_bound <= v && v <= right_bound))
            continue;
        if (v == w)
            return level;
        if (MAX_LEVEL <= level)
            continue;
        int p = primes[level];
        q.push(v + p);
        q.push(v - p);
        q.push(v * p);
        q.push(v / p);
        next_level_size += 4;
    }
    return -1;
}

void solve() {
    int h, w;
    cin >> hex >> h >> w;
    cout << bfs(h, w) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    rep(i, t) solve();

    return 0;
}