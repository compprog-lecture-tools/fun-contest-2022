#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

using node_t = uint32_t;
using kernelnode_t = uint8_t;
using solution_t = uint64_t;
using localcoins_t = uint32_t;


struct Edge
{
    node_t u;
    node_t v;
};

struct KernelEdge
{
    kernelnode_t u;
    kernelnode_t v;
};

struct DP_Entry
{
    solution_t without;
    solution_t with;
};

int main()
{
    // Approach:
    // Bruteforce every combination

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n, m;
    cin >> n >> m;

    vector<localcoins_t> coins(n);

    for(auto& coin : coins)
        cin >> coin;

    vector<Edge> edges(m);

    for(auto& e : edges)
    {
        node_t u, v;
        cin >> u >> v;
        u--;
        v--;
        e = { u, v };
    }

    solution_t max_coins = 0;

    for(size_t config = 0; n >= 64 || (config < (1 << n)); config++)
    {
        // Check that there are no contradictions inside our problem kernel set
        if(any_of(edges.begin(), edges.end(), [config](Edge e) {
                    return (config & (1 << e.u)) && (config & (1 << e.v));
        }))
            continue;

        solution_t cur_coins = 0;

        for(node_t u = 0; u < n; u++)
        {
            if(config & (1 << u))
                cur_coins += coins[u];
        }

        max_coins = max(max_coins, cur_coins);
    }

    cout << max_coins << '\n';
}