from sre_constants import AT_END_STRING
import sys
def minimalRaggedText(lengths, n, lineWidth):
    dp = [float('inf')] * (n+1)
    dp[0] = 0

    for i in range(n):
        currlen = 0
        j = i
        while (j < n and currlen + lengths[i] <= lineWidth):
            currlen += lengths[j]
            j+=1
            dp[j] = min(dp[j], dp[i] + (lineWidth-currlen)**2)
            currlen+=1
    
    ans = float('inf')
    currlen = 0
    i = n-1
    while i >= 0 and currlen <= lineWidth:
        ans = min(ans, dp[i+1])
        currlen += lengths[i] + (i < n-1)
        i-=1
    print(ans)

n = int(input())
l = [len(i) for i in input().split()]
lineWidth = int(input())
minimalRaggedText(l, n, lineWidth)