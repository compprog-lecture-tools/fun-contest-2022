#include "testlib.h"
#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

using node_t = uint32_t;
using edge_t = pair<node_t, node_t>;

namespace std
{
    template <>
    struct hash<edge_t>
    {
        size_t operator()(edge_t e) const
        {
            return (size_t)e.first | ((size_t)e.second << 32);
        }
    };
}

class UF
{
    node_t* entries;

public:
    UF(size_t size) : entries(new node_t[size]()) {}

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




const string_view ZERO_SAMPLE = R"(0 0
)";

const string_view SIMPLE_SAMPLE = R"(3 2
3 6 4
1 2
2 3
)";

const string_view CLIQUE3_SAMPLE = R"(3 3
4 5 8
1 2
2 3
1 3
)";

const string_view HOUSE_SAMPLE = R"(5 8
5 10 11 5 2
1 2
1 3
1 4
2 3
2 4
3 4
3 5
4 5
)";

template<typename F>
static void testcase(string name, string desc, F f) {
    ofstream desc_file(name + ".desc");
    desc_file << desc;
    string in_file = name + ".in";
    freopen(in_file.c_str(), "w", stdout);
    f();
}

static void predefined(string name, string desc, string_view content) {
    testcase(name, desc, [&]() { cout << content; });
}



static void random_sample(string name, string desc, size_t n, size_t m)
{
    testcase(name, desc, [&]()
    {
        cout << n << ' ' << m << '\n';

        for(size_t i = 0; i < n; i++)
        {
            cout << (rnd.next(1000000000) + 1) << (i == n - 1 ? '\n' : ' ');
        }

        UF uf(n+1);

        vector<edge_t> edges;
        edges.reserve(m);

        unordered_set<edge_t> edges_set;

        for(size_t i = 0; i < n - 1; i++)
        {
            edge_t e;

            do
            {
                e.first = rnd.next(n) + 1;
                e.second = rnd.next(n) + 1;

                if(e.first > e.second)
                    swap(e.first, e.second);
            }
            while(!uf.merge(e.first, e.second));

            edges.push_back(e);
            edges_set.insert(e);
        }

        for(size_t i = n - 1; i < m; i++)
        {
            edge_t e;

            do
            {
                e.first = rnd.next(n) + 1;
                e.second = rnd.next(n) + 1;

                if(e.first > e.second)
                    swap(e.first, e.second);
            }
            while(e.first == e.second || edges_set.find(e) != edges_set.end());

            edges.push_back(e);
            edges_set.insert(e);
        }

        for(uint32_t i : rnd.perm<uint32_t>(m))
        {
            cout << edges[i].first << ' ' << edges[i].second << '\n';
        }
    });
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    rnd.setSeed(8346173064822485599ll);

    predefined("zero", "Consists of an empty graph", ZERO_SAMPLE);
    predefined("sample1", "Three nodes in a linear setup", SIMPLE_SAMPLE);
    predefined("sample2", "A clique of 3 nodes", CLIQUE3_SAMPLE);
    predefined("sample3", "A 4-clique with another node connected to 2", HOUSE_SAMPLE);

    random_sample("max", "Contains a maximum-sized graph", 100000, 100008);

    for(size_t i = 1; i < 10; i++)
    {
        size_t n = rnd.next(100000) + 1;
        size_t m = n - 1 + 2 + rnd.next(8);

        auto num_str = toString(i);
        random_sample("random" + num_str, "Random Sample #" + num_str, n, m);
    }

    return 0;
}