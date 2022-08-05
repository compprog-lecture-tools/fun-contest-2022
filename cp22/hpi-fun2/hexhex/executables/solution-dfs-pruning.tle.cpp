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

ll left_bound = 0;
ll right_bound = 2e9;

const int INF = 1e9;
const int MAX_SOLUTION = 12;

int global_min = MAX_SOLUTION;
int w;
int dfs(ll x, int d = 0) {
    if (left_bound > x || right_bound < x)
        return INF;
    if (w == x) {
        global_min = min(global_min, d);
        return d;
    }
    if (d >= global_min)
        return INF;
    ll p = primes[d];
    return min({dfs(x + p, d + 1), dfs(x - p, d + 1), dfs(x * p, d + 1),
                dfs(x / p, d + 1)});
}

void solve() {
    int h;
    cin >> hex >> h >> w;
    global_min = MAX_SOLUTION;
    int s = dfs(h);
    cout << (s != INF ? s : -1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    rep(i, t) solve();

    return 0;
}