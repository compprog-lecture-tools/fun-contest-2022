#include <bits/stdc++.h>
#include<cmath>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    //content
    int countOfNumbers;
    cin >> countOfNumbers;
    vector<string> numbers(countOfNumbers);
    rep(i, countOfNumbers) {
        cin >> numbers[i];
    }
    string digitOrder;
    cin >> digitOrder;
    map<char, int> charVals;

    // map characters to their digitOrder
    for (int i = 0; i < digitOrder.length(); ++i) {
        charVals[digitOrder[i]] = i;
    }

    for (int i = 1; i < numbers.size(); ++i) {
        string s1 = numbers[i - 1];
        string s2 = numbers[i];

        if (s1 == s2) {
            continue;
        }
        if(s1.length() < s2.length()){
            continue;
        } else if (s1.length() > s2.length()){
            cout << "NO";
            cout << endl;
            return 0;
        }

        // advance to the first non-matching digit at the same position in the two numbers
        int len = min(s1.length(), s2.length());
        int j = 0;
        for (int j = 0; j < len && s1[j] == s2[j]; ++j);

        // compare non-matching digits based on the ordering
        if (charVals[s1[j]] > charVals[s2[j]]) {
            cout << "NO";
            cout << endl;
            return 0;
        }
    }

    cout << "YES";
    cout << endl;
    return 0;
}
