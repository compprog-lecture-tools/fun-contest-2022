#include <bits/stdc++.h>

#define all(a) begin(a), end(a)
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define sz(x) (int)size(x)

using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
using ld=long double;

void insert(int a) {
	cout << "? insert " <<a << endl << flush;
}

int remove() {
	int r;
	cout << "? remove" << endl << flush;
	cin >> r;
	return r;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	insert(1);
	insert(2);
	insert(0);
	insert(0);
	insert(2);

	cout << array{"! pq", "! set", "! stack", "! queue"}[remove() + remove()] << endl;

	return 0;
}
