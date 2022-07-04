#include <iostream>
#include <string>

using namespace std;

constexpr static char MAP[] = {
    '1',
    'S',
    'E',
    0,
    'Z',
    0,
    0,
    '8',
    0,
    0, 0, 0, 0, 0, 0, 0,
    'A',
    0,
    0,
    0,
    '3',
    0,
    0,
    'H',
    'I',
    'L',
    0,
    'J',
    'M',
    0,
    'O',
    0,
    0,
    0,
    '2',
    'T',
    'U',
    'V',
    'W',
    'X',
    'Y',
    '5',
};

int main() {
    string s;
    cin >> s;

    auto size = s.size();
    auto mid = (size + 1) / 2;
    auto mirrored = true;
    auto palindrome = true;
    for (size_t i = 0; i < mid; ++i) {
        auto c = s[i];
        auto c2 = s[size - i - 1];
        palindrome &= (c == c2);
        mirrored &= (c == MAP[c2 - '1']);
    }

    cout << s << " -- is "
         << (mirrored ? (palindrome ? "a mirrored palindrome" : "a mirrored string")
                      : (palindrome ? "a regular palindrome" : "not a palindrome"))
         << ".\n";
}
