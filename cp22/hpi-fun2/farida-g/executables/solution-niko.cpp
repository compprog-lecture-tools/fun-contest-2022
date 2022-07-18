#include <bits/stdc++.h>

using namespace std;
#define rep(i,a,b) for (int i = a; i < (b); i++)
#define sz(x) (int)size(x)
#define endl '\n'

using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
using ld=long double;

vll coins;
vector<vector<pair<ll, ll>>> dp;
vi enter;
vector<vector<pair<int, int>>> adj;
int cur_time = 0;
int cur_edge = 0;

const int MAX_EXTRA = 9;

void discover(int idx, int par) {
	enter[idx] = cur_time++;
	for (auto&[v, e] : adj[idx]) {
		if (v == par)
			continue;
		if (enter[v] == -1) {
			discover(v, idx);
		} else if (enter[v] < enter[idx]) {
			// found non-tree edge
			auto it = find(adj[v].begin(), adj[v].end(), pair(idx, -1));
			it->second = cur_edge;
			e = cur_edge++;
		}
	}
}

void tree_dp(int u, int par) {
	int extra = 0;
	enter[u] = cur_time++;
	for (auto&[v, e] : adj[u]) {
		extra |= (e != -1) ? (1 << e) : 0;

		if (v == par)
			continue;
		if (enter[v] == -1) {
			tree_dp(v, u);
		}
	}

	rep(mask, 0, 1 << MAX_EXTRA) {
		ll include = ((extra & mask) == extra) * coins[u];
		ll exclude = 0;
		for (auto&[v, e] : adj[u]) {
			if (enter[v] < enter[u] || e != -1)
				continue;
			include += dp[v][mask & (~extra)].second;
			exclude += dp[v][mask].first;
		}
		dp[u][mask] = {max(include, exclude), exclude};
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout.precision(20);


	int n, m; cin >> n >> m;
	coins.resize(n);
	dp.resize(n);
	rep(i,0,n) dp[i].assign(1 << MAX_EXTRA, {});
	adj.resize(n);
	enter.assign(n, -1);

	rep(i,0,n) cin >> coins[i];
	rep(i,0,m) {
		int u, v; cin >> u >> v;
		u--,  v--;
		adj[u].push_back({v, -1});
		adj[v].push_back({u, -1});
	}

	discover(0, -1);

	cur_time = 0;
	enter.assign(n, -1);
	tree_dp(0, -1);

	ll out = 0;
	rep(i, 0, 1 << MAX_EXTRA) out = max({out, dp[0][i].first, dp[0][i].second});
	cout << out << endl;

	return 0;
}
