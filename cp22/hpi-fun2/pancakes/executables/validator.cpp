#include <testlib.h>
#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 100'000;
int main(int argc, char *argv[])
{
    setName("describe your validator here");
    registerTestlibCmd(argc, argv);

    const int n = inf.readInt(1, MAX_N, "n");
    const int k = inf.readInt(0, n, "k");
    vector<bool> pancakes = vector<bool>(n, true);
    inf.readLine();
    for (int i = 0; i < n; ++i)
    {
        string currentOrientation = inf.readWord();
        pancakes[i] = currentOrientation.compare("up") == 0;
    }
    int a0 = ouf.readInt(0, n, "a_0");
    ouf.ensuref(a0 > -1, "a_0 must be at least 0");
    ouf.ensuref(a0 <= k, "a_0 must not be more than k");
    for (int i = 0; i < a0; ++i)
    {
        int ai = ouf.readInt(1, n, "a_i");
        for (int j = 0; j < ai; ++j)
        {
            pancakes[j] = not pancakes[j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        // ouf.ensuref(pancakes[i], "all pancakes must be turned correctly.");
        if (not pancakes[i])
        {
            quit(_wa, "all pancakes must be turned correctly.");
        }
    }

    // Use inf (.in file), ouf (submission output) and ans (.ans file)
    // Use quit(_wa, message) or quitf(_wa, format_string, args...) to report wrong answers
    // Exchange _wa by _pe if the format is wrong (should mostly be taken care of by the
    // input functions of ouf)

    quit(_ok, "");
}