#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 100'000;

int main(int argc, char *argv[])
{
    setName("describe your validator here");
    registerTestlibCmd(argc, argv);

    const int n = inf.readInt(1, MAX_N, "n");
    vector<bool> pancakes = vector<bool>(n, true);
    inf.readLine();
    string pancakeOrientation = inf.readWord();
    for (int i = 0; i < n; ++i)
    {
        pancakes[i] = pancakeOrientation[i] == 'u';
    }
    int a0 = ouf.readInt(0, n, "a_0");
    for (int i = 0; i < a0; ++i)
    {
        int ai = ouf.readInt(1, n, "a_i");
        for (int j = 0; j < (ai / 2); ++j)
        {
            int prevPancake = ai - 1 - j;
            swap(pancakes[prevPancake], pancakes[j]);
            pancakes[prevPancake] = not pancakes[prevPancake];
            pancakes[j] = not pancakes[j];
        }
        if (ai % 2 == 1)
        {
            // If we flipped an uneven number of pancakes, we still need to flip the on in the middle.
            int middle = ai / 2;
            pancakes[middle] = not pancakes[middle];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        // ouf.ensuref(pancakes[i], "all pancakes must be turned correctly.");
        if (not pancakes[i])
        {
            for (bool pancake : pancakes)
            {
                cout << (pancake ? 'u' : 'd');
            }
            cout << endl;
            quit(_wa, "all pancakes must be turned correctly.");
        }
    }

    // Use inf (.in file), ouf (submission output) and ans (.ans file)
    // Use quit(_wa, message) or quitf(_wa, format_string, args...) to report wrong answers
    // Exchange _wa by _pe if the format is wrong (should mostly be taken care of by the
    // input functions of ouf)

    quit(_ok, "Solution correct");
}