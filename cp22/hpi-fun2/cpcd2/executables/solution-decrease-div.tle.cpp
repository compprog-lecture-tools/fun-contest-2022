#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        int d = 2 * n / (k * k + k);
        while (d && n % d)
            --d;

        if (!d) {
            cout << "-1\n";
            continue;
        }

        for (int i = 1; i < k; ++i)
            cout << (i * d) << ' ';
        cout << (n - (k * k - k) * d) << '\n';
    }

    return 0;
}
