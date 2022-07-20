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

    int n; cin >> n;
    vi a(n); trav(ai,a) {
        string s; cin >> s;
        ai = sz(s);
    }
    int w; cin >> w;

    vl dp(n+1, infl); // min cost if ending the last line before word i
    dp[0] = 0;

    rep(i,n) {
        int len = 0;
        rep(j,i,n) {
            if (len + a[j] <= w) {
                len += a[j];
                dp[j+1] = min(dp[j+1], dp[i] + (w-len)*(w-len));
                len++;
            }
        }
    }

    ll ans = infl;
    int len = 0;
    for (int i = n-1; i >= 0 && len <= w; i--) {
        ans = min(ans, dp[i+1]);
        len += a[i] + (i < n-1);
    }
    cout << ans;

    return 0;
}

