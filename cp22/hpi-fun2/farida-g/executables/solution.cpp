#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

using node_t = uint32_t;
using kernelnode_t = uint8_t;
using solution_t = uint64_t;
using inputcoins_t = uint32_t;

class UF
{
    vector<node_t> entries;

public:
    UF(size_t size) : entries(size) {}

    node_t find(node_t p)
    {
        node_t root = p;
        while(entries[root])
            root = entries[root];
        while (p != root)
        {
            node_t newp = entries[p];
            entries[p] = root;
            p = newp;
        }
        return root;
    }

    bool merge(node_t x, node_t y)
    {
        node_t i = find(x);
        node_t j = find(y);
        if (i == j)
            return false;

        entries[i] = j;

        return true;
    }
};

template<typename T>
struct Edge
{
    node_t u;
    node_t v;
};

using edge_t = Edge<node_t>;
using kerneledge_t = Edge<kernelnode_t>;

struct DP_Entry
{
    solution_t without;
    solution_t with;
};

int main()
{
    // Approach:
    // The graph is nearly a tree. By removing a hard kernel set of up to m - n + 1 nodes, we can gain a forest.
    // Then we can bruteforce all possible combinations for the kernel set and do a tree-DP for the rest.

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n, m;
    cin >> n >> m;

    vector<inputcoins_t> coins;
    coins.reserve(n + 1);
    coins.push_back(0); // virtual 0 node

    for(size_t i = 0; i < n; i++)
    {
        inputcoins_t coin;
        cin >> coin;
        coins.push_back(coin);
    }

    vector<edge_t> edges;
    edges.reserve(m);

    UF uf(n+1);

    // Find max. m - n + 1 nodes whose removal makes a forest

    // Assigns each kernel node a more convenient densely packed index.
    unordered_map<node_t, kernelnode_t> kernel_nodes;

    for(size_t i = 0; i < m; i++)
    {
        node_t u, v;
        cin >> u >> v;

        edges.push_back({ u, v });

        if(!uf.merge(u, v))
        {
            // This can only happen m - n + 1 times
            // By removing an incident node, cycle edges get overkilled.
            kernel_nodes.insert({ u, kernel_nodes.size() });
        }
    }

    // For each kernel node, lists the adjacent regular nodes.
    vector<vector<node_t>> kernel_nodes_regular_neighbours(kernel_nodes.size());

    // Stores the parent node for our DP.
    // Since by removing kernel nodes the remaining graph might be split into multiple components,
    // a virtual node '0' without own coins supersedes the parent of each tree.
    vector<node_t> parent(n - kernel_nodes.size() + 1);

    vector<node_t> regular_ordered;
    regular_ordered.reserve(n + 1 - kernel_nodes.size());
    regular_ordered.push_back(0); // Dummy because we start at 1

    // Create topo-sort for the non-kernel forest
    {
        vector<vector<node_t>> adj(n+1);

        for(auto e : edges)
        {
            adj[e.u].push_back(e.v);
            adj[e.v].push_back(e.u);
        }

        vector<node_t> regular_new_id(n+1);

        vector<bool> visited(n+1);

        for(node_t start = 1; start <= n; start++)
        {
            if(visited[start] || kernel_nodes.find(start) != kernel_nodes.end())
                continue;

            regular_new_id[start] = regular_ordered.size();
            regular_ordered.push_back(start);
            visited[start] = true;
            stack<node_t> to_visit;
            to_visit.push(start);

            while(!to_visit.empty())
            {
                node_t u = to_visit.top();
                to_visit.pop();

                for(node_t v : adj[u])
                {
                    if(!visited[v])
                    {
                        auto kernel_it = kernel_nodes.find(v);

                        if(kernel_it == kernel_nodes.end())
                        {
                            visited[v] = true;
                            to_visit.push(v);
                            regular_new_id[v] = regular_ordered.size();
                            regular_ordered.push_back(v);
                            parent[regular_new_id[v]] = regular_new_id[u];
                        }
                        else
                        {
                            kernel_nodes_regular_neighbours[kernel_it->second].push_back(regular_new_id[u]);
                        }
                    }
                }
            }

        }
    }

    // For each kernel node, fill in its neighbours
    vector<kerneledge_t> kernel_internal_edges;
    for(auto [u, v] : edges)
    {
        auto maybe_kernel_u = kernel_nodes.find(u);
        auto maybe_kernel_v = kernel_nodes.find(v);

        if(maybe_kernel_u != kernel_nodes.end() && maybe_kernel_v != kernel_nodes.end())
        {
            kernel_internal_edges.push_back({ maybe_kernel_u->second, maybe_kernel_v->second });
        }
    }

    solution_t max_coins = 0;
    vector<DP_Entry> opt(parent.size());

    // Apply "regular_ordered" permutation to coins.
    vector<inputcoins_t> regular_coins(parent.size());
    for(node_t new_u = 0; new_u < opt.size(); new_u++)
    {
        regular_coins[new_u] = coins[regular_ordered[new_u]];
    }

    vector<inputcoins_t> kernel_coins(kernel_nodes.size());

    for(auto [u, i] : kernel_nodes)
    {
        kernel_coins[i] = coins[u];
    }

    // Brute-Force loop for the kernel nodes.
    // One of the initializations must yield the optimal solution in the subsequent DP.
    for(size_t config = 0; config < (1 << kernel_nodes.size()); config++)
    {
        // Check that there are no contradictions inside our problem kernel set
        if(any_of(kernel_internal_edges.begin(), kernel_internal_edges.end(), [config](kerneledge_t e) {
                    return (config & (1 << e.u)) && (config & (1 << e.v));
        }))
            continue;

        // Add coins right at the beginning, such that we can remove them for each active kernel node's neighbour.
        transform(regular_coins.begin(), regular_coins.end(), opt.begin(), [](inputcoins_t val) { return DP_Entry{ .without = 0, .with = val }; });

        // Initialization according to the kernel nodes.
        for(auto extra_node_mapping : kernel_nodes)
        {
            node_t u = extra_node_mapping.first;
            node_t i = extra_node_mapping.second;

            if(config & (1 << i))
            {
                // This kernel node is included for this iteration config.

                // It is axiomatic for some nodes to not be included.
                for(node_t v : kernel_nodes_regular_neighbours[i])
                    opt[v].with = 0;

                // It is also axiomatic for this node to be included.
                opt[0].without += kernel_coins[i];
            }
        }

        // Regular DP of normal nodes.
        for(node_t u = opt.size() - 1; u > 0; u--)
        {
            node_t v = parent[u];

            assert(v < u);

            opt[v].without += max(opt[u].with, opt[u].without);
            opt[v].with += opt[u].without;
        }

        max_coins = max(max_coins, opt[0].without);
    }

    cout << max_coins << '\n';
}