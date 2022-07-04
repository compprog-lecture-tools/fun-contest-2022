#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;

vector<ll> values = {22, 10, 15, 97, 10, 25, 80, 22, 56, 5};

map<string, string> out = {{"no22no10no15no97no10no25no80no22no56no5yes", "queue"},
                           {"no5no56no22no80no25no10no97no15no10no22yes", "stack"},
                           {"no5no10no15no22no25no56no80no97yes",         "set"},
                           {"no5no10no10no15no22no22no25no56no80no97yes", "pq"},};

int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    ll queries = 32;
    for (ll x : values) {
        queries--;
        cout << "? insert " << x << endl;
    }
    string a;
    string res;
    vector<ll> removed;
    while (queries > 0) {
        queries--;
        cout << "? empty" << endl;
        string cur;
        cin >> cur;
        res += cur;
        if (cur == "yes" || queries <= 0) break;
        queries--;
        cout << "? remove" << endl;
        cin >> cur;
        removed.push_back(stol(cur));
        res += cur;
    }
    auto it = out.find(res);
    if (it == out.end()) {
        sort(all(removed));
        sort(all(values));
        values.erase(unique(all(values)), values.end());
        if (removed == values) {
            cout << "! hash" << endl;
        } else {
            cout << "! none" << endl;
        }
    } else {
        cout << "! " << it->second << endl;
    }

}
