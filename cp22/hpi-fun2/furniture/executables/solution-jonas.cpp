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

    int n,m; cin >> n;

    vi t(n); trav(ti,t) cin >> ti;

    cin >> m;
    vvi adj(n);
    vi indeg(n,0);
    rep(i,m) {
        int u,v; cin >> u >> v; u--,v--;
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int> q;
    rep(i,n) if (indeg[i] == 0) q.push(i);
    vi topo;
    while (sz(q)) {
        auto v = q.front(); q.pop();
        topo.push_back(v);
        trav(e, adj[v]) {
            indeg[e]--;
            if (indeg[e] == 0) q.push(e);
        }
    }

    // the graph should be a DAG
    assert(topo.size() == n);

    vl dp(n,0);
    trav(i, topo) {
        dp[i] += t[i];
        trav(e, adj[i]) dp[e] = max(dp[e], dp[i]);
    }
    cout << *max_element(all(dp));

    return 0;
}

