#include <testlib.h>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX_T = 30;
const int MAX_N = 1'000'000'000;

const string_view SAMPLE = R"(3
6 3
21 3
7 4
)";


template <class F>
void testcase(string name, string desc, F f) {
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

int find_max_k(int n) {
    int k = (int)sqrt(2 * n) - 1;
    assert(((ll)k * k + k) / 2 <= n);
    return k;
}

int random_k(int n) {
    int max_k = find_max_k(n);
    // Strongly prefer smaller k, to reduce size of output files
    return rnd.wnext(1, max_k, -5);
}

int small_k(int n) {
    int max_k = find_max_k(n);
    return rnd.next(2, min(5, max_k));
}

void fixed_numbers_testcase(string name, string desc, vector<int> nums) {
    assert(size(nums) <= MAX_T);
    testcase(name, desc, [&]() {
        println(size(nums));
        for (auto n : nums)
            println(n, small_k(n));
    });
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    rnd.setSeed(2366474113169584551ll);

    predefined("sample", "Sample", SAMPLE);


    // Check for buggy solutions
    predefined("check-large-divisors",
               "Fails if only divisors <= sqrt(n) are checked",
               "1\n80 2\n");


    // Special large numbers
    fixed_numbers_testcase("primes", "Large primes", {
        887828203, 700262881, 955025693, 120244979, 120244979, 120244979, 120244979, 566318653, 343757053, 504007489, 999999001, 999999017, 999999029, 999999043, 999999059, 999999067, 999999103, 999999107, 999999113, 999999131, 999999137, 999999151, 999999163, 999999181, 999999191, 999999193, 999999197, 999999223, 999999229, 999999323,
    });

    fixed_numbers_testcase("many-divisors", "Some highly composite numbers", {1081080, 1441440, 2162160, 2882880, 3603600, 4324320, 6486480, 7207200, 8648640, 10810800, 14414400, 17297280, 21621600, 32432400, 36756720, 43243200, 61261200, 73513440, 110270160, 122522400, 147026880, 183783600, 245044800, 294053760, 367567200, 551350800, 698377680, 735134400});

    vector<int> semi;
    for (int p1 : {10007, 10009, 10037, 10039, 10061})
        for (int p2 : {10007, 10009, 10037, 10039, 10061})
            semi.push_back(p1 * p2);
    fixed_numbers_testcase("semi-primes", "Some random products of two similar primes", semi);

    testcase("max-divisors", "Testcases with k=2 and n=10^9-1", []() {
        assert(999'999'999 <= MAX_N);
        println(MAX_T);
        for (int i = 0; i < MAX_T; ++i)
            println(999'999'999, 2);
    });


    // Lots of small (n, k) pairs
    vector<pair<int, int>> pairs;
    for (int n = 1; n <= 28; ++n) {
        int k = 1;
        while ((k * k + k) / 2 <= n)
            pairs.emplace_back(n, k++);
        // Only add a single impossible pair per n
        if (k <= n)
            pairs.emplace_back(n, rnd.next(k, n));
    }
    int case_count = ((int)size(pairs) + MAX_T - 1) / MAX_T;
    for (int i = 0; i < case_count; ++i)
        testcase(
            "small-pairs-" + toString(i + 1),
            "Small pairs (case " + toString(i + 1) + "/" + toString(case_count) + ")",
            [&]() {
                int l = i * MAX_T, r = min(l + MAX_T, (int)size(pairs));
                println(r - l);
                for (int j = l; j < r; ++j)
                    println(pairs[j].first, pairs[j].second);
        });

    // Random test cases
    for (int i = 1; i <= 3; ++i)
        for (auto small : {true, false})
            testcase("random-" + toString(i) + (small ? "-small-k" : ""),
                    small ? "Random (small k)" : "Random",
                    [&]() {
                println(MAX_T);
                for (int j = 0; j < MAX_T; ++j) { 
                    int n = rnd.next(1, MAX_N);
                    println(n, small ? small_k(n) : random_k(n));
                }
            });

    return 0;
}
