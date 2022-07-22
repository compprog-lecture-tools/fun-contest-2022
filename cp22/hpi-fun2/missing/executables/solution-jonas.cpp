//region template
#include <bits/stdc++.h>

#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep(...)        GET_MACRO(__VA_ARGS__, repn, rep0)(__VA_ARGS__)
#define rep0(i, b)      for(int i = 0; i < (b); ++i)
#define repn(i, a, b)   for(int i = (a); i < (b); ++i)
#define trav(a, b)      for(auto& a : b)
#define all(a)          (a).begin(),(a).end()
#define endl            '\n'
#define sz(x)           ((int)(x).size())
#define tests           int ___;cin>>___;while(___--)

using namespace std;
using ll = int64_t;
using ld = long double;
using ul = uint64_t;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vpi = vector<pi>;

static constexpr int inf = (int)1e9 + 5;
static constexpr ll infl = (ll)1e18 + 5;
static mt19937 rng((uint32_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
//endregion

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    string s; cin >> s;
    int n = sz(s);

    vvi pal(n+1, vi(n+1, 0));

    rep(l, 0, n+1)
        rep(i,0,n-l+1)
            pal[i][i+l] = l <= 1 || (s[i] == s[i+l-1] && pal[i+1][i+l-1]);

    vi dp(n+1, inf);
    dp[0] = 0;
    rep(i,n) {
        rep(j,i+1)
            if (pal[j][i+1]) dp[i+1] = min(dp[i+1], dp[j] + 1);
    }

    cout << dp[n];

    return 0;
}

