#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        ll mx = 0, stair = (k * k + k) / 2;
        for (ll i = 1; i * i <= n; ++i) {
            if (n % i) continue;
            if (stair * i > n) break;
            mx = i;
        }

        if (!mx) {
            cout << "-1\n";
            continue;
        }

        for (int i = 1; i < k; ++i)
            cout << (i * mx) << ' ';
        cout << (n - (stair - k) * mx) << '\n';
    }

    return 0;
}
