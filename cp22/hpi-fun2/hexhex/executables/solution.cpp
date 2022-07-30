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

ll left_bound = -1e9;
ll right_bound = 1e9;

int w;
int max_depth;
bool _dfs(ll x, int d = 0) {
    if (left_bound > x || right_bound < x)
        return false;
    if (w == x)
        return true;
    if (d == max_depth)
        return false;
    ll p = primes[d];
    return _dfs(x + p, d + 1) || _dfs(x - p, d + 1) || _dfs(x * p, d + 1) ||
           _dfs(x / p, d + 1);
}

bool dfs(int x, int max_d) {
    max_depth = max_d;
    return _dfs(x);
}

void solve() {
    const int MAX_SOLUTION = 12;

    int h;
    cin >> hex >> h >> w;

    rep(i, MAX_SOLUTION + 1) {
        if (dfs(h, i)) {
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    rep(i, t) solve();

    return 0;
}