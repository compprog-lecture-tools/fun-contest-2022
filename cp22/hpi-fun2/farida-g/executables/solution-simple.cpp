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
    // 0 reserved for "no parent"
    vector<node_t> entries;

public:
    UF(size_t size) : entries(size+1) {}

    node_t find(node_t p)
    {
        p++;
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

    solution_t overall() const
    {
        return max(with, without);
    }
};

// Find max. m - n + 1 nodes whose removal makes a forest
static vector<node_t> select_kernel_nodes(size_t n, const vector<edge_t>& edges)
{
    unordered_set<node_t> kernel;
    UF uf(n);

    for(auto e : edges)
    {
        if(!uf.merge(e.u, e.v))
            kernel.insert(e.u);
    }

    return move(vector<node_t>(kernel.begin(), kernel.end()));
}

static vector<vector<node_t>> make_adj(size_t n, const vector<edge_t>& edges)
{
    vector<vector<node_t>> adj(n);

    for(auto e : edges)
    {
        adj[e.u].push_back(e.v);
        adj[e.v].push_back(e.u);
    }

    return move(adj);
}

// Finds all edges inside the kernel-induced subgraph and return them by new kernel-relative node indices.
static vector<kerneledge_t> select_kernel_edges(const vector<node_t>& kernel, const vector<edge_t>& edges)
{
    vector<kerneledge_t> kernel_edges;

    for(auto e : edges)
    {
        auto it1 = find(kernel.begin(), kernel.end(), e.u);
        auto it2 = find(kernel.begin(), kernel.end(), e.v);

        if(it1 != kernel.end() && it2 != kernel.end())
            kernel_edges.push_back({ (kernelnode_t)(it1 - kernel.begin()), (kernelnode_t)(it2 - kernel.begin()) });
    }

    return move(kernel_edges);
}

// Does a DFS while solving the DP in post-order.
static DP_Entry do_dfs(const vector<inputcoins_t>& coins, const vector<vector<node_t>>& adj, vector<bool>& visited, node_t u)
{
    if(visited[u])
        return {};

    visited[u] = true;

    DP_Entry opt { .without = 0, .with = coins[u] };

    for(node_t v : adj[u])
    {
        auto child_opt = do_dfs(coins, adj, visited, v);
        opt.without += child_opt.overall();
        opt.with += child_opt.without;
    }

    return opt;
}

int main()
{
    // Approach:
    // The graph is nearly a tree. By removing a hard kernel set of up to m - n + 1 nodes, we can gain a forest.
    // Then we can bruteforce all possible combinations for the kernel set and do a tree-DP for the rest.

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n, m;
    cin >> n >> m;

    vector<inputcoins_t> coins(n);
    for(auto& c : coins)
        cin >> c;

    vector<edge_t> edges(m);
    for(auto& e : edges)
    {
        node_t u, v;
        cin >> u >> v;
        u--;
        v--;
        e = { u, v };
    }

    auto adj = make_adj(n, edges);
    auto kernel = select_kernel_nodes(n, edges);
    auto kernel_edges = select_kernel_edges(kernel, edges);

    solution_t max_coins = 0;
    vector<bool> visited(n);

    // Brute-Force loop for the kernel nodes.
    // One of the configurations must yield the optimal solution in the subsequent DP.
    for(size_t iteration = 0; iteration < (1 << kernel.size()); iteration++)
    {
        bitset<64> config(iteration);

        // "config" represents the kernel subset chosen for the independent-set solution.

        // Check that there are no contradictions inside our problem kernel set
        if(any_of(kernel_edges.begin(), kernel_edges.end(), [config](kerneledge_t e) {
            return (config[e.u] && config[e.v]);
        }))
            continue;

        solution_t cur_opt = 0;
        fill(visited.begin(), visited.end(), false);

        // Initialization according to the included kernel nodes.
        for(size_t i = 0; i < kernel.size(); i++)
        {
            auto k = kernel[i];
            visited[k] = true;

            if(config[i])
            {
                // This node is axiomatically included, so add its value
                cur_opt += coins[k];

                // Remove neighbours of selected node
                for(auto v : adj[k])
                    visited[v] = true;
            }
        }

        // Since there may be multiple trees disconnected by a removed kernel node,
        // Attempt to start DFS for every node.
        for(node_t u = 0; u < n; u++)
            cur_opt += do_dfs(coins, adj, visited, u).overall();

        max_coins = max(max_coins, cur_opt);
    }

    cout << max_coins << '\n';
}