# missing

Find the minimum number of words to split the string into, so that every word is a palindrome.

Can be restated: Find the minimum number of cuts, so that the resulting words are palindromes. (For the result add 1).

## Recursive approach

The problem can be solved with a recursive DP-approach.

Let s be the string.

$minCuts(s, i, j) = 0$, if $i = j$ or $s[i..j]$ is palindrome.
$minCuts(s, i, j) = min(minCuts(s, i, k) + 1 + minCuts(s, k+1, j))$

A naive approach would be possible in O(2^n).

## DP

DP Solution: Store number of cuts for string up to index, store for every pair of index if the string between them is a palindrome.

- For every index i
  - Set minCut to i
  - Take every index j up to i
  - If s[i] = s[j]
    - If i == j or i - j == 1, a trivial palindrome has been found
    - If there is a palindrome between j+1 and i-1, a palindrome can be expanded
    - Update the palindrome array
    - Set minCut to the minimum of minCut and 1 + number of cuts for i-1 (stored in array)
  - Store minCut in cut array
- Return cut value for last index + 1

In total the runtime is in O(n^2).
