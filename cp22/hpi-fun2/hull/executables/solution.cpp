#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const ll INF = numeric_limits<long long>::max() / 4;
    ll min_x = INF;
    ll max_x = -INF;
    ll min_y = INF;
    ll max_y = -INF;

    int n;
    cin >> n;

    rep(i, n)
    {
        ll x, y;
        cin >> x >> y;
        min_x = min(min_x, x);
        max_x = max(max_x, x);
        min_y = min(min_y, y);
        max_y = max(max_y, y);
    }

    ll circumference = 2 * (max_x - min_x) + 2 * (max_y - min_y);
    cout << circumference << endl;

    return 0;
}