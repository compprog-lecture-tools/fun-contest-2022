#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

using node_t = uint32_t;
using solution_t = uint64_t;
using inputcoins_t = uint32_t;

struct edge_t
{
    node_t u;
    node_t v;
};

int main()
{
    // Approach:
    // Bruteforce every combination

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n, m;
    cin >> n >> m;

    vector<inputcoins_t> coins(n);

    for(auto& coin : coins)
        cin >> coin;

    vector<edge_t> edges(m);

    for(auto& e : edges)
    {
        node_t u, v;
        cin >> u >> v;
        u--;
        v--;
        e = { u, v };
    }

    solution_t max_coins = 0;

    for(size_t iteration = 0; n >= 64 || (iteration < (1 << n)); iteration++)
    {
        bitset<64> subset(iteration);

        // Check that there are no contradictions inside our independent set
        if(any_of(edges.begin(), edges.end(), [subset](edge_t e) {
                    return subset[e.u] && subset[e.v];
        }))
            continue;

        solution_t cur_coins = 0;

        for(node_t u = 0; u < n; u++)
        {
            if(subset[u])
                cur_coins += coins[u];
        }

        max_coins = max(max_coins, cur_coins);
    }

    cout << max_coins << '\n';
}