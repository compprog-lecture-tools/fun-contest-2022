n = int(input()) + 1

furniture = list(map(int, input().split()))

m = int(input())
g = [[0]]*n

count = [0] * n

for i in range(m):
    current = tuple(map(int, input().split()))
    if g[current[0]][0] != 0:
        g[current[0]].append(current[1])
    else:
        g[current[0]] = [current[1]]
    count[current[1]] += 1

empty = [i for i in range(1, n) if count[i]==0]
dp = [0] + furniture

while len(empty) != 0:
    el = empty.pop(0)
    for i in range(len(g[el])):
        if(g[el][i] == 0):
            continue
        dp[g[el][i]] = max(dp[g[el][i]], dp[el] + furniture[g[el][i] - 1])
        count[g[el][i]] -= 1
        if count[g[el][i]] == 0:
            empty.append(g[el][i])

print(max(dp))