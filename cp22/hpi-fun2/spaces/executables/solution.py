# code adapted from: https://www.geeksforgeeks.org/word-wrap-problem-space-optimized-solution/

import sys
def minimalRaggedText(lengths, n, lineWidth):
    dp = [0] * n
    dp[n - 1] = 0
    for i in range(n - 2, -1, -1):
        currlen = -1
        dp[i] = sys.maxsize
        for j in range(i, n):
            currlen += (lengths[j] + 1)
            if (currlen > lineWidth):
                break
            if (j == n - 1):
                cost = 0
            else:
                cost = ((lineWidth - currlen) * (lineWidth - currlen) + dp[j + 1])
            if (cost < dp[i]):
                dp[i] = cost
    print(dp[0])

n = int(input())
l = [len(i) for i in input().split()]
lineWidth = int(input())
minimalRaggedText(l, n, lineWidth)