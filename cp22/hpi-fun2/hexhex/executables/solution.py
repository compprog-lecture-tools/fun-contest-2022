import io
import os

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

primes = [
    2, 3, 5, 7,
    11, 13, 17, 19,
    23, 29, 31, 37,
    41, 43, 47, 53
]


left_bound = int(-1e9)
right_bound = int(1e9)

max_depth = 0
w = 0


def dfs(x, d=0):
    if not left_bound <= x <= right_bound:
        return False
    if x == w:
        return True
    if d == max_depth:
        return False
    p = primes[d]
    return dfs(x + p, d + 1) or dfs(x - p, d + 1) or dfs(x * p, d + 1) or dfs(x // p, d + 1)


def solve():
    global max_depth, w
    h, w = map(int, input().split())
    for i in range(13):
        max_depth = i
        if dfs(h):
            print(i)
            return
    print(-1)


t = int(input())
for i in range(t):
    solve()
