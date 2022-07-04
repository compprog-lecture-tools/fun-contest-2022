#include <bits/stdc++.h>

#define rep(a, s, b)   for(int a = (s); a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = vector<int>;

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


	int test; cin >> test;
	while (test--) {
		ll n,k; cin >> n >> k;
		vector<ll> factors={1,n};
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				factors.push_back(i);
				factors.push_back(n/i);
			}
		}
		sort(all(factors), greater<ll>());
		auto triag = [] (ll i) {
			return i * (i+1) /2;
		};
		for (auto d : factors) {
			ll target = n / d;
			if (triag(k) > target) continue;
			ll i = 0, rem_sum = target;
			for (int p = 0; p < k; p++) {
				i = max(i+1, rem_sum - triag(target) + triag(target - k + p + 1));
				cout << d*i << " ";
				rem_sum -= i;
			}
			goto next;
		}
		cout << -1;
next:;
	 cout << endl;
	}

    cout.flush();
    return 0;
}

