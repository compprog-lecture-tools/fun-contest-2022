#include <testlib.h>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX_T = 30;
const int MAX_N = 1'000'000'000;

optional<int> load_and_check_next(InStream& in, int n, int k) {
    int a0 = in.readInt(-1, n, "a_0");
    if (a0 == -1)
        return {};
    in.ensuref(a0 != 0, "a_0 may not be 0");

    int prev = a0, g = a0;
    ll sum = a0;
    for (int i = 1; i < k; ++i) {
        int ai = in.readInt(1, n, "a_i");
        in.ensuref(ai > prev, "sequence is not strictly increasing (%d <= %d)", ai, prev);
        g = gcd(g, ai);
        sum += ai;
    }

    in.ensuref(sum == n, "sum is not n (%lld vs. %d)", sum, n);
    return g;
}

int main(int argc, char* argv[]) {
    setName("describe your validator here");
    registerTestlibCmd(argc, argv);

    int t = inf.readInt(1, 1000, "t");
    while (t--) {
        int n = inf.readInt(1, MAX_N, "n");
        int k = inf.readInt(1, n, "k");

        auto ans_gcd = load_and_check_next(ans, n, k);
        auto out_gcd = load_and_check_next(ouf, n, k);

        if (!ans_gcd && !out_gcd)
            continue;
        quitif(!out_gcd, _wa, "existing solution not found");
        quitif(!ans_gcd, _fail, "contestant found answer that shouldn't exist");

        quitif(*ans_gcd > *out_gcd, _wa, "non-optimal gcd (%d vs. %d)", *ans_gcd, *out_gcd);
        quitif(*ans_gcd < *out_gcd,
               _fail,
               "contestant has better gcd than answer (%d vs. %d, n = %d, k = %d)",
               *ans_gcd, *out_gcd, n, k);
    }

    quit(_ok, "");
}
