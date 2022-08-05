#include <bits/stdc++.h>
#include <testlib.h>
#define ll long long

using namespace std;

// clang-format off
int primes[] = {
    2, 3, 5, 7,
    11, 13, 17, 19,
    23, 29, 31, 37,
    41, 43, 47, 53,
    59, 61, 67, 71,
    73, 79, 83, 89, 
};
// clang-format on

const ll left_bound = 0;
const ll right_bound = 2e9;

const int MAX_LEVEL = 12;
int bfs(int h, int w) {
    int level = 0;
    int level_size = 1;
    int next_level_size = 0;

    queue<ll> q;
    q.push(h);

    while (!q.empty() && level <= MAX_LEVEL) {
        if (level_size == 0) {
            level++;
            level_size = next_level_size;
            next_level_size = 0;
        }
        ll v = q.front();
        q.pop();
        level_size--;
        if (!(left_bound <= v && v <= right_bound))
            continue;
        if (v == w)
            return level;
        if (MAX_LEVEL <= level)
            continue;
        int p = primes[level];
        q.push(v + p);
        q.push(v - p);
        q.push(v * p);
        q.push(v / p);
        next_level_size += 4;
    }
    return -1;
}

int random_walk(ll h, int max_solution) {
    for (int i = 0; i < max_solution; i++) {
        int p = primes[i];
        ll x = h;
        do {
            int op = rnd.next(0, 3);
            if (op == 0)
                x = h + p;
            else if (op == 1)
                x = h - p;
            else if (op == 2)
                x = h * p;
            else
                x = h / p;
        } while (!(left_bound <= x && x <= right_bound));
        h = x;
    }
    return h;
}

const string_view SAMPLE1 = R"(6
1 1
1 2
42 69
DEAD BAD
C001 C0DE
BAD CAB1E)";

template <class F> void testcase(string name, string desc, F f) {
    ofstream desc_file(name + ".desc");
    desc_file << desc;
    string in_file = name + ".in";
    freopen(in_file.c_str(), "w", stdout);
    f();
}

void predefined(string name, string desc, string_view content) {
    testcase(name, desc, [&]() { cout << content; });
}

void sample(int num, string_view content) {
    auto num_str = toString(num);
    predefined("sample" + num_str, "Sample #" + num_str, content);
}

const int MIN_X = left_bound;
const int MAX_X = right_bound;
const int MAX_TC = 100;
const int MAX_SUM = 200;

void print_tc(const vector<pair<int, int>> &tc) {
    assert(tc.size() <= MAX_TC);
    cout << dec << tc.size() << "\n";
    for (auto [h, w] : tc)
        cout << hex << h << " " << w << "\n";
    cout << dec;
}

void random(int num) {
    auto num_str = toString(num);
    testcase("random" + num_str, "Random #" + num_str, [&]() {
        vector<pair<int, int>> testcases;
        int sum = 0;
        for (int i = 0; i < MAX_TC && sum < MAX_SUM; i++) {
            int h = rnd.next(MIN_X, MAX_X);
            int max_len = rnd.next(1, min(MAX_LEVEL + 1, MAX_SUM - sum));

            int w = random_walk(h, max_len);
            int solution = bfs(h, w);

            if (solution == -1)
                solution = max_len;
            sum += solution;

            if (sum <= MAX_SUM)
                testcases.emplace_back(h, w);
        }
        print_tc(testcases);
    });
}

void anti_pruning(int num, function<ll(ll, ll)> op) {
    auto num_str = toString(num);
    testcase("anti-pruning" + num_str, "Anti-pruning #" + num_str, [&]() {
        vector<pair<int, int>> testcases;
        int solution = 3;

        for (int i = 0; i < min(MAX_TC, MAX_SUM / solution); i++) {
            ll w, h;
            do {
                h = rnd.next(MIN_X, MAX_X);
                w = h;
                for (int j = 0; j < solution; j++) {
                    w = op(w, primes[j]);
                }

            } while (!(left_bound <= w && w <= right_bound));
            testcases.emplace_back(h, w);
        }
        print_tc(testcases);
    });
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    rnd.setSeed(-5483929211109496621ll);

    sample(1, SAMPLE1);

    for (int i = 1; i <= 10; i++)
        random(i);

    for (int i = 1; i <= 3; i++)
        anti_pruning(i, divides<ll>());
    for (int i = 4; i <= 6; i++)
        anti_pruning(i, plus<ll>());
    for (int i = 6; i <= 9; i++)
        anti_pruning(i, minus<ll>());
    for (int i = 10; i <= 12; i++)
        anti_pruning(i, multiplies<ll>());

    return 0;
}
