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

// region number theory
// source: kactl
using ull = uint64_t;
ull mod_pow(ull b, ull e, ull mod) {
    ull ans = 1;
    for(; e; b = b*b % mod, e /= 2)
        if (e & 1) ans = ans*b % mod;
    return ans;
}

bool miller_rabin(ull n) {
    if (n < 2 || n % 6 % 4 != 1) return n - 2 < 2;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
            s = __builtin_ctzll(n-1), d = n >> s;
    for (auto a : A) {
        ull p = mod_pow(a, d, n), i = s;
        while (p != 1 && p != n-1 && a % n && i--) p = p*p % n;
        if (p != n-1 && i != s) return false;
    }
    return true;
}

ull rho(ull n) {
    if (n % 2 == 0) return 2;
    auto f = [n](ull x) { return (x*x % n + 1) % n; };
    for (ull i = 2;;i++) {
        ull x = i, y = f(x), g = gcd(x - y, n);
        while (g == 1)
            x = f(x), y = f(f(y)), g = gcd(x - y, n);
        if (g != n) return g;
    }
}

vector<ull> factor(ull n) {
    if (n == 1) return {};
    if (miller_rabin(n)) return {n};
    ull x = rho(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), all(r));
    return l;
}
// endregion


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ull n; cin >> n;

    auto f = factor(n);

    assert(sz(f) == 2);
    f[0] %= 100;
    f[1] %= 100;
    sort(all(f));

    string s; cin >> s;
    vi se(2,0);
    int i = 0;
    while (max(se[0], se[1]) < f[0]) {
        vi cnt(2,0);
        while (max(cnt[0], cnt[1]) < f[1]) {
            assert(i < sz(s));
            cnt[s[i++] == '7']++;
        }
        se[cnt[1] > cnt[0]]++;
    }
    assert(i == sz(s));

    cout << (se[0] > se[1] ? '3' : '7');

    return 0;
}

