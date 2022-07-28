#include <testlib.h>
#include <bits/stdc++.h>

using namespace std;

const string_view SAMPLE1 = R"(2
1 1
-1 -1)";

const string_view SAMPLE2 = R"(11
1 2
1 -2
-1 -5
-2 -3
-2 3
4 -1
3 -3
2 -4
2 0
-3 -1
0 0)";

template <class F>
void testcase(string name, string desc, F f)
{
    ofstream desc_file(name + ".desc");
    desc_file << desc;
    string in_file = name + ".in";
    freopen(in_file.c_str(), "w", stdout);
    f();
}

void predefined(string name, string desc, string_view content)
{
    testcase(name, desc, [&]()
             { cout << content; });
}

void sample(int num, string_view content)
{
    auto num_str = toString(num);
    predefined("sample" + num_str, "Sample #" + num_str, content);
}

const int MIN_N = 1e5;
const int MAX_N = 1e5;
const int MIN = -1e9;
const int MAX = 1e9;

auto random(int n)
{
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << rnd.next(MIN, MAX) << " "
             << rnd.next(MIN, MAX) << endl;
    }
}

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    rnd.setSeed(674636925294265588ll);

    sample(1, SAMPLE1);
    sample(2, SAMPLE2);

    predefined("overflow", "Overflow #1", R"(2
1000000000 1000000000
-1000000000 -1000000000)");

    predefined("overflow2", "Overflow #2", R"(2
1000000000 -1000000000
-1000000000 1000000000)");

    for (int i = 1; i <= 100; i++)
        testcase("random" + toString(i),
                 "Random #" + toString(i),
                 [&]
                 { random(rnd.next(MIN_N, MAX_N)); });

    for (int i = 1; i <= 10; i++)
        testcase("maximum" + toString(i),
                 "Maximum #" + toString(i),
                 [&]
                 { random(MAX_N); });

    return 0;
}