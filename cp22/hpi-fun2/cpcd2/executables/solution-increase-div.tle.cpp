#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        ll stair = (k * k + k) / 2;

        int mx = 0;
        for (int i = 1; stair * i <= n; ++i)
            if (n % i == 0)
                mx = i;

        if (mx) {
            for (int i = 1; i < k; ++i)
                cout << (i * mx) << ' ';
            cout << (n - (k * k - k) * mx) << '\n';
        } else
            cout << "-1\n";
    }

    return 0;
}
