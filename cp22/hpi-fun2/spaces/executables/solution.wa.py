
import sys
def greedySolution(lengths, n, lineWidth):
    res = 0
    currLength = 0
    for wl in lengths:
        if(currLength+wl > lineWidth):
            res += ((lineWidth-currLength+1)**2)
            currLength = wl+1
        else:
            currLength += (wl+1)
    print(res)


n = int(input())
l = [len(i) for i in input().split()]
lineWidth = int(input())
greedySolution(l, n, lineWidth)