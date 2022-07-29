#include <testlib.h>
#include <bits/stdc++.h>

using namespace std;

const string_view SAMPLE1 = R"(3
1 1
1 -1
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

const int MIN_N = 3;
const int MAX_N = 2e5;
const int MIN = -1e9;
const int MAX = 1e9;

auto random(int n)
{
    cout << n << endl;
    set<pair<int, int>> used;
    pair<int, int> point;
    for (int i = 0; i < n; i++)
    {
        do
        {
            point = {rnd.next(MIN, MAX), rnd.next(MIN, MAX)};
        } while (used.count(point));
        used.insert(point);
        cout << point.first << " " << point.second << endl;
    }
}

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    rnd.setSeed(674636925294265588ll);

    sample(1, SAMPLE1);
    sample(2, SAMPLE2);

    predefined("overflow", "Overflow #1", R"(3
1000000000 1000000000
1000000000 -1000000000
-1000000000 -1000000000)");

    predefined("overflow2", "Overflow #2", R"(3
999999999 -999999999
999999999 -999999999
-999999999 999999999)");

    predefined("collinear1", "Collinear #1", R"(4
0 1
1 1
2 1
3 1)");
    predefined("collinear2", "Collinear #2", R"(4
1 0
1 1
1 2
1 3)");
    predefined("collinear3", "Collinear #3", R"(4
0 0
1 1
2 2
3 3)");
    predefined("collinear4", "Collinear #4", R"(4
0 0
-1 1
-2 2
-3 3)");

    for (int i = 1; i <= 10; i++)
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