#include <bits/stdc++.h>
#include <random>

using namespace std;
using ll = long long;

static mt19937 rng((uint32_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        ll mx = 0, stair = (k * k + k) / 2;
        for (ll i = 1; i * i <= n; ++i) {
            if (n % i) continue;
            for (ll d : {i, n / i})
                if (stair * d <= n)
                    mx = max(mx, d);
        }

        if (!mx) {
            cout << "-1\n";
            continue;
        }

        // Start with a 1,2,...,k sequence as a default. Then randomly split
        // the remaining multiples of mx into k parts randomly, and add them
        // in sorted order to the increasing sequence
        int rem = n / mx - stair;
        uniform_int_distribution<int> dist(0, rem);
        vector<int> splits(k + 1);
        for (int i = 1; i < k; ++i)
            splits[i] = dist(rng);
        splits[k] = rem;
        sort(begin(splits), end(splits));

        vector<int> adds(k);
        for (int i = 0; i < k; ++i)
            adds[i] = splits[i + 1] - splits[i];
        sort(begin(adds), end(adds));

        for (int i = 0; i < k; ++i)
            cout << ((i + 1 + adds[i]) * mx) << ' ';
        cout << '\n';
    }

    return 0;
}
